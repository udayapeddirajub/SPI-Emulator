#ifndef SLAVEDEVICE_H
#define SLAVEDEVICE_H

#include "SPI.h"

// A simple concrete SPI slave device that echoes back received bytes.
class SlaveDevice : public SPI_Slave {
public:
    // Called during SPI transfer; here slave simply returns same byte.
    uint8_t transfer(uint8_t data) override {
        return data; // Echo the received byte as response
    }
};

#endif // SLAVEDEVICE_H
