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

        Box& operator=(const Box& other){
            cout<<"Copy Assignment  "<<other.label<<endl;
            if(this != &other){
                label = other.label;
            }
            return *this;
        }

        Box& operator=(Box&& other) noexcept{
            cout<<"Move Assignment  "<<other.label<<endl;
            if(this != &other){
                label = other.label;
                other.label = "new parcel"; 
            }
            return *this;
        }
        void show() const{
            std::cout << "Parcel contains: " << label << "\n";
        }
};

int main()
{
    Box b1("original");
    Box b2("parcel");
    b2 = b1;
    b1.show();
    b2.show();
    Box b3("move B3");//move(b2);
    b3 = move(b1);
    b1.show();
    b2.show();
    b3.show();
    return 0;
}