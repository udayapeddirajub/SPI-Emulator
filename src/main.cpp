#include <iostream>
#include "SPI.h"
#include "SlaveDevice.h"

int main() {
    SPI_Master master;    // Instantiate SPI master object
    SlaveDevice slave;    // Instantiate SPI slave object

    master.selectSlave(&slave);  // Select slave to communicate with

    // Prepare a vector of bytes to send
    std::vector<uint8_t> data_to_send = {0xA5, 0x5A, 0xFF};

    // Perform SPI transfer: send data_to_send, receive response bytes
    std::vector<uint8_t> received = master.transferData(data_to_send);

    // Print sent bytes in hexadecimal format
    std::cout << "Sent: ";
    for (auto d : data_to_send) std::cout << std::hex << int(d) << " ";
    
    // Print received bytes in hexadecimal format
    std::cout << "\nReceived: ";
    for (auto d : received) std::cout << std::hex << int(d) << " ";
    std::cout << std::endl;

    // Return success
    return 0;
}
