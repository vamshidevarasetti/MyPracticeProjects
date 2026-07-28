#include <iostream>
#include<memory>

using namespace std;

class Car
{
	public:
		Car()
		{
			cout<<"Car constructor"<<endl;
		}
		~Car()
		{
			cout<<"Car destructor"<<endl;
		}
};

int main()
{
	auto p1 = make_shared<Car>();
	cout << "usecount p1= "<< p1.use_count()<<endl;
	auto p2=p1;
	cout << "usecount p1= "<< p1.use_count()<<endl;
	cout << "usecount p2= "<< p2.use_count()<<endl;
	{
		auto p3 = p1;
		cout << "usecount p1= "<< p1.use_count()<<endl;
        cout << "usecount p2= "<< p2.use_count()<<endl;
        cout << "usecount p3= "<< p3.use_count()<<endl;
	}
	cout << "usecount p1= "<< p1.use_count()<<endl;
    cout << "usecount p2= "<< p2.use_count()<<endl;
	return 0;
}