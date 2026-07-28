#include <iostream>
#include<memory>

using namespace std;

class Child;

class Parent
{
	public:
		weak_ptr<Child> child;

        void parentAction() {
        cout << "Parent performing action!" << endl;
    }
		
		~Parent(){ cout << "Parent destructor"<<endl;}
		
};
class Child
{
	public:
		weak_ptr<Parent> parent;

        // Member function demonstrating the use of expired() and lock()
        void interactWithParent() 
        {
            // 1. Using expired() to check object status
            if (parent.expired()) {
                cout << "Child says: Parent object is no longer alive!" << endl;
                return;
            }

            // 2. Using lock() to safely acquire a shared_ptr
            if (auto parentSp = parent.lock()) {
                cout << "Child acquired parent lock successfully." << endl;
                parentSp->parentAction(); // Safe to access Parent methods
            } else {
                cout << "Failed to lock Parent." << endl;
            }
        }
		
		~Child(){ cout << "child destructor"<<endl;}
		
};


int main()
{
	auto p1 = make_shared<Parent>();
	auto c1 = make_shared<Child>();

	p1->child = c1;
	c1->parent = p1;

	cout<< "parent ref count" << p1.use_count()<<endl;
	cout<< "child ref count" << c1.use_count()<<endl;

    c1->interactWithParent(); // Child interacts with Parent
    p1.reset(); // Destroy Parent
    if(p1 == nullptr) {
        cout << "Parent has been destroyed." << endl;
    }   
    c1->interactWithParent(); // Child tries to interact with Parent again
	
	return 0;
}