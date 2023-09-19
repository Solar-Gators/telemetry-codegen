#include <iostream>
#include <sstream>
#include <cstring>
#include <csignal>
#include "RX0.hpp"

int main() {
    uint8_t data[2] = {0x37, 0x44};
    SolarGators::DataModules::RX0 RX0;

    RX0.FromByteArray(data);

    std::cout << "input first: " << RX0.GetFirstVal() << std::endl;
    std::cout << "input second: " << RX0.GetSecondVal() << std::endl;
    if (RX0.GetFirstVal() != data[0]) {
        std::cout << "first is wrong!" << std::endl;
        return -1;
    }

    if (RX0.GetSecondVal() != data[1]) {
        std::cout << "second is wrong!" << std::endl;
        return -1;
    }

    RX0.ToByteArray(data);
    if (data[0] != 0x37) {
        std::cout << "first to byte array is wrong!" << std::endl;
        return -1;
    }
    if (data[1] != 0x44) {
        std::cout << "second to byte array is wrong!" << std::endl;
        return -1;
    }
}
