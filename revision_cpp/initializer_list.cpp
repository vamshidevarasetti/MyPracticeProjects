#include <initializer_list>
#include <iostream>
using namespace std;

class CANFrame
{
public:

    CANFrame(initializer_list<uint8_t> data)
    {
        cout << "Frame Size = "
             << data.size();

        for(auto byte : data)
        {
            cout << " " << hex << static_cast<int>(byte);
        }
    }
};

int main()
{
    CANFrame frame{0x12,0x34,0x56,0x78};
}

// class Student
// {
// public:

//     Student(int age)
//     {
//         cout << "Age Constructor\n";
//     }

//     Student(initializer_list<int> list)
//     {
//         cout << "Initializer List Constructor\n";
//     }
// };

// int main()
// {
//     Student s1(20); // Calls the constructor with an int parameter
//     Student s2{20}; // Calls the initializer_list constructor

//     return 0;
// }