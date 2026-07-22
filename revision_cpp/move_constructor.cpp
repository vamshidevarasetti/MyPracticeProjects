#include <iostream>
#include <string>

using namespace std;

class buffer
{
	int *data;
	
	public : 
		buffer (int value): data(new int(value))
		{cout << "standard constructor"<<endl;}
		
		buffer (const buffer &other)
		{
			data = new int(*other.data);
			cout << "copy constructor"<<endl;
		}
		buffer (buffer&& other) noexcept
		{
			data = other.data;
			other.data = nullptr;
			cout << "move constructor"<<endl;
		}

        buffer& operator=(const buffer& other)
		{
			if(this==&other)
			{
				return *this;
			}
            delete data;
            data = new int(*other.data);
			cout << "copy Assignment"<<endl;
			return *this;
		}

        buffer& operator=(buffer&& other) noexcept
		{
			if(this!=&other)
			{
				delete data;
				data = other.data;
				other.data= nullptr;
			}
			cout << "Move Assignment"<<endl;
			return *this;
		}
        ~buffer()
        {
            delete data;
            cout << "destructor called" << endl;   
        }
		void display()
		{
			cout << "data = " << *data <<endl;
		}

};

int main()
{
	buffer b1(100);

	//buffer b2 = std::move(b1);

    buffer b2(200);

    b1 = b2;

    //b1 = move(b2);

	b1.display();

	b2.display();

    return 0;

}