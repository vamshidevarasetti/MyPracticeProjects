#include <iostream>
#include <functional>

using namespace std;

typedef function<void()> fptr;

class worker{
    public:
        void process(const string & str){
            cout<<"worker::process called   "<<str << endl;
        }
};

int main(){
    worker w;
    string msg = "Hello vamshi";
    fptr fp= bind(&worker::process, &w, cref(msg));
    fp();

    return 0;
}