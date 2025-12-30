#include <iostream>

bool isLittleEndian() {
    uint16_t num = 0x1;
    // Check the lowest byte of the memory
    return *reinterpret_cast<uint8_t*>(&num) == 0x1;
}

int main() {
    if (isLittleEndian()) {
        std::cout << "System is Little Endian" << std::endl;
    } else {
        std::cout << "System is Big Endian" << std::endl;
    }
    return 0;
}
