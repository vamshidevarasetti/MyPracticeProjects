#include <iostream>

using namespace std;

class student
{
	private:
		int *marks;

	public:
		student(int m)
		{
			marks = new int(m);
			cout << "constructor" <<endl;
		}
		student(const student& other)
		{
			marks = new int(*other.marks);
			cout << "copy constructor" <<endl;
		}
		student& operator=(const student& other)
		{
			if(this != &other)
			{
				delete marks;
				marks = new int(*other.marks);
			}
			cout << "copy Assignment" <<endl;
			return *this;
		}
		student(student&& other) noexcept
		{
			marks = other.marks;
			other.marks = nullptr;
			cout << "move constructor" <<endl;
		}
		student& operator=(student&& other) noexcept
		{
			if(this != &other)
			{
				delete marks;
				marks = other.marks;
				other.marks = nullptr;
			}
			
			cout << "move Assignment" <<endl;
			return *this;
		}
		~student()
		{
			delete marks;
            cout << "destructor called" <<endl;
		}
        void display()                          // Display function
        {
            if (marks)
                cout << *marks << endl;         // Print stored value
            else
                cout << "No Data" << endl;      // Object has been moved from
        }

};

int main(){
	student s1(20);
	student s2 = s1;
	student s3(30);
	s3= s1;
	student s4 = move(s1);
	student s5(50);
	s5 = move(s4);
}