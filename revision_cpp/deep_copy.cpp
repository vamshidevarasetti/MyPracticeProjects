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
	student s2 = s1;
    *s2.age = 33;
	s1.display();
	s2.display();
    return 0;
}