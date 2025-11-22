#include "SPI.h"
#include "SlaveDevice.h"
#include <gtest/gtest.h>

// Test case to verify single byte transfer returns same byte (echo)
TEST(SPITest, Transfer) {
    SPI_Master master;     // Create SPI master object
    SlaveDevice slave;     // Create SPI slave object
    master.selectSlave(&slave);  // Select slave
    
    uint8_t sent = 0xAB;          // Test byte to send
    uint8_t received = master.transfer(sent);  // Transfer byte
    
    EXPECT_EQ(sent, received);    // Verify sent equals received (echo)
}

// Test case for multi-byte SPI transfer correctness
TEST(SPITest, TransferMultiple) {
    SPI_Master master;
    SlaveDevice slave;
    master.selectSlave(&slave);

    std::vector<uint8_t> data = {0x01, 0x02, 0x03};  // Data to send
    auto received = master.transferData(data);        // Transfer data
    
    EXPECT_EQ(data, received);  // Expect echoed data matches sent
}

// Entry point for Google Test runner
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
