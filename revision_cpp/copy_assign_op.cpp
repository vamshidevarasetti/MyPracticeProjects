#include <iostream>
#include <string>

using namespace std;

class student
{
    public:
    int * age;

    student(int a): age(new int(a))
    {
    }
	
	student (const student &other)
	{
		age = new int(*other.age);
	}

    student& operator=(const student& other)
	{
        if (this == &other)
            return *this; // Handle self-assignment
        if(this != &other)
        {
            delete age; // Free existing resource
            age = new int(*other.age); // Allocate new memory and copy value
        }
		
		return *this;
	}

    ~student()
    {
        delete age;
        cout<< "destructor called" << endl; 
    }
	
	void display()
	{
		cout<< "student age = " << *age <<endl; 
	}
};

int main()
{
	student s1(22);
	//student s2 = s1;
    //*s2.age = 33;
    student s2(34);
    s1.display();
	s2.display();
    s2 = s1;
	s1.display();
	s2.display();
    return 0;
}