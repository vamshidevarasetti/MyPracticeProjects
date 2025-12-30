#include <iostream>
#include <iomanip>
#include <type_traits>
#include <vector>

int main() {
    std::cout << "Sizeof examples:\n";

    std::cout << "Size of char: " << sizeof(char) << " byte(s)\n";        // Usually 1
    std::cout << "Size of int: " << sizeof(int) << " byte(s)\n";          // Typically 4
    std::cout << "Size of float: " << sizeof(float) << " byte(s)\n";      // Typically 4
    std::cout << "Size of double: " << sizeof(double) << " byte(s)\n";    // Typically 8
    std::cout << "Size of int*: " << sizeof(int*) << " byte(s)\n";        // Pointer size (usually 8 on 64-bit)

    std::cout << "Alignof examples:\n";

    std::cout << "Alignment of char: " << alignof(char) << " byte(s)\n";       // Usually 1
    std::cout << "Alignment of int: " << alignof(int) << " byte(s)\n";         // Typically 4
    std::cout << "Alignment of float: " << alignof(float) << " byte(s)\n";     // Typically 4
    std::cout << "Alignment of double: " << alignof(double) << " byte(s)\n";   // Typically 8
    std::cout << "Alignment of int*: " << alignof(int*) << " byte(s)\n"; 

    return 0;
}