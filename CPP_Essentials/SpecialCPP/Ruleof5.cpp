#include <iostream>
#include <utility>
using namespace std;

class myclass{
    int* data;

    public:
        myclass(int value){
            data = new int(value);
            cout<<"constructor = " << *data<<endl;
        }
        ~myclass(){
            cout<<"destructor called"<<endl;
            delete data;
        }
        //copy constructor
        myclass(const myclass& other) noexcept{
            data = new int(*other.data);
            cout<<"copy constructor = " << *data<<endl;
        }
        //move constructor
        myclass(myclass&& other) noexcept{
            data = other.data;
            other.data = nullptr;
            cout<<"move constructor = " << *data<<endl;
        }

        //copy assignment
        myclass& operator=(const myclass& other){
            if(this != &other){
                delete data;
                data = new int(*other.data);
                std::cout << "Copy Assignment: copied " << *data << "\n";
            }
            return *this;
        }
        //move assignment
        myclass& operator=(myclass&& other){
            if(this != &other){
                delete data;
                data = other.data;
                other.data = nullptr;
                std::cout << "Move Assignment: moved resource\n";
            }
            return *this;
        }
        // Utility function
        void show() const {
            if (data) std::cout << "Value = " << *data << "\n";
            else std::cout << "No data\n";
        }


};

int main(){
    myclass a(10);
    myclass b = a;
    myclass c(20);
    c=b;
    myclass d = move(c);
    a.show();
    b.show();
    c.show();
    d.show();
    return 0;
}

