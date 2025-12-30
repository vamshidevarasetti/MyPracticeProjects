#include <iostream>
#include <string>

using namespace std;

class Box{
    private:
        string label;

    public:
        Box(const string& lbl):label(lbl){
            cout<<"Constructor  "<<label<<endl;
        }

        Box(const Box& other): label(other.label){
            cout<<"Copy Constructor  "<<other.label<<endl;
        }

        Box(Box&& other) noexcept: label((other.label)){
            cout<<"Move Constructor  "<<other.label<<endl;
            other.label = "moved";
        }
};

int main()
{
    Box b1("original");
    Box b2 = b1;
    Box b3 = move(b2);
    return 0;
}