#include <iostream>
#include <sstream>
#include <cstring>
#include <csignal>
#include "RX0.hpp"

int main() {
    uint8_t data[4] = {0x37, 0x44, 0x20, 0x40};
    SolarGators::DataModules::RX0 RX0;

    RX0.FromByteArray(data);

    std::cout << "input first: " << RX0.GetFirstVal() << std::endl;
    std::cout << "input second: " << RX0.GetSecondVal() << std::endl;
    if (RX0.GetFirstVal() != 0x4437) {
        std::cout << "first is wrong!" << std::endl;
        return -1;
    }

    if (RX0.GetSecondVal() != 0x4021) {
        std::cout << "second is wrong!" << std::endl;
        return -1;
    }

    RX0.ToByteArray(data);
    if (data[0] != 0x37 || data[1] != 0x44) {
        std::cout << "first to byte array is wrong!" << std::endl;
        return -1;
    }
    if (data[2] != 0x20 || data[3] != 0x40) {
        std::cout << "second to byte array is wrong!" << std::endl;
        return -1;
    }
}
