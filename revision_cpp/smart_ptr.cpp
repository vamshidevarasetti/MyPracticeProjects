#include <iostream>                     // Include input/output library
#include <memory>                       // Include smart pointer library
using namespace std;                    // Use standard namespace

class Student
{
public:

    Student()                           // Constructor
    {
        cout << "Constructor\n";        // Print when object is created
    }

    ~Student()                          // Destructor
    {
        cout << "Destructor\n";         // Print when object is destroyed
    }

    void display()                      // Display function
    {
        cout << "Learning Smart Pointers\n"; // Print message
    }
};

int main()
{
    unique_ptr<Student> uptr = make_unique<Student>(); // Create unique_ptr
    unique_ptr<Student> ptr = make_unique<Student>(); // Create unique_ptr

    auto unqptr = make_unique<Student>();
    unqptr = move(uptr); // Transfer ownership to unqptr

    ptr->display();                     // Access object using ->
    unqptr->display();                  // Access object using ->
    if(uptr == nullptr)                    // Check if uptr is null
    {
        cout << "uptr is null\n";      // Print message
    }

}                                       // unique_ptr automatically destroys object