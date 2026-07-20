#include <iostream>                    // Includes input/output library
#include <string>                      // Includes string library
using namespace std;                   // Use standard namespace

class Employee
{
public:
    string name;                       // Employee name
    int age;                           // Employee age

    Employee(string n, int a)          // Parameterized constructor
        : name(n), age(a)              // Initialize members
    {
        cout << "Parameterized Constructor\n"; // Print message
    }

    Employee(const Employee& other)    // User-defined copy constructor
    {
        name = other.name;             // Copy name from source object
        age = other.age;               // Copy age from source object

        cout << "Copy Constructor\n";  // Print message
    }

    void display()                     // Display function
    {
        cout << name << " " << age << endl; // Print object data
    }
};

int main()
{
    Employee e1("Vamshi",34);          // Create first employee

    Employee e2 = e1;                  // Invoke copy constructor

    e1.display();                      // Display original employee

    e2.display();                      // Display copied employee
}