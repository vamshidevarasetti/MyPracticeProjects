#include <iostream>
#include <vector>

using namespace std;

class Test{
    int data;

    public:
        Test(int value): data(value){};

        void showdata(){
            cout<<"data = "<<data<<endl;
        }
};

int main(){
    vector<Test> vec{Test(10), Test(20), Test(30)};

    auto element = [](Test t){t.showdata();};

    for(auto e:vec)
    {
        element(e);
    }
    return 0;
}
