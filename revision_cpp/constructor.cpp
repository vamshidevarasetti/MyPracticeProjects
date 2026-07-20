#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string name;
    int age;
    Employee(string n, int a) : name(n), age(a)
    {
        //cout << "Parameterized Constructor\n";
        //cout << "Name: " << name << ", Age: " << age << endl;
    }
    //Employee(string name): name(name)
    //{
      //  cout << "Parameterized Constructor with name only\n";
        //cout << "Name: " << name << endl;
    //}
    Employee(): Employee("Mahi", 5)
    {
        cout << "Default Constructor with delegation\n";
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{
    Employee emp1("vamshi", 34);
    //Employee emp2;
    //Employee emp3("John");

    return 0;
}