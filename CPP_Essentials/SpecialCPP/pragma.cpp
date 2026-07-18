#include <iostream>

//#pragma pack(push, 1)   // set alignment to 1 byte

struct PackedStruct {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
};
struct B {
    alignas(8) char c;
    //char c;
    //int x;
};

//#pragma pack(pop)       // restore previous alignment

int main() {
    std::cout << "Size of PackedStruct: " << sizeof(PackedStruct) << " bytes\n";
    std::cout << "Size of B: " << sizeof(B) << " bytes\n";
}
