#include <iostream>
#include <sstream>
#include <cstring>
#include <csignal>
#include "RX0.hpp"

int main() {
    uint8_t data[8];
    float first = 1.1;
    float second = 2.2;
    memcpy(&data[0], &first, sizeof(first));
    memcpy(&data[4], &second, sizeof(second));

    SolarGators::DataModules::RX0 RX0;

    RX0.FromByteArray(data);

    std::cout << "input first: " << RX0.GetFirstVal() << std::endl;
    std::cout << "input second: " << RX0.GetSecondVal() << std::endl;
    if (RX0.GetFirstVal() != first) {
        std::cout << "first is wrong!" << std::endl;
        return -1;
    }

    if (RX0.GetSecondVal() != second) {
        std::cout << "second is wrong!" << std::endl;
        return -1;
    }
}
