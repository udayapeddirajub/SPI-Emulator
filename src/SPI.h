#ifndef SPI_H
#define SPI_H

#include <vector>
#include <cstdint>

// Abstract base class representing an SPI Slave device.
// Any concrete SPI slave must implement the transfer method.
class SPI_Slave {
public:
    // Transfers a single byte to/from the slave.
    // 'data' is the byte sent from master,
    // return value is the byte received from slave.
    virtual uint8_t transfer(uint8_t data) = 0;
};

// Class representing the SPI Master device.
class SPI_Master {
private:
    // Pointer to currently selected slave device.
    SPI_Slave* selected_slave;

public:
    // Constructor initializes selected_slave to null.
    SPI_Master() : selected_slave(nullptr) {}

    // Method to select the slave device to communicate with.
    void selectSlave(SPI_Slave* slave) {
        selected_slave = slave;  // Store pointer to chosen slave
    }
    
    // Transfer a single byte over SPI by calling slave's transfer method.
    // Throws runtime error if no slave is selected.
    uint8_t transfer(uint8_t data) {
        if (!selected_slave) 
            throw std::runtime_error("No slave selected");
        return selected_slave->transfer(data);
    }

    // Transfer a sequence of bytes. For each byte, perform transfer and store response.
    std::vector<uint8_t> transferData(const std::vector<uint8_t>& data_out) {
        std::vector<uint8_t> data_in;  // Vector to hold bytes received from slave
        for (auto d : data_out) {
            data_in.push_back(transfer(d));  // Transfer each byte and store response
        }
        return data_in;  // Return all received bytes
    }
};

#endif // SPI_H
