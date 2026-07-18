#include <iostream>
using namespace std;

template <typename T>

class Sharedpointer{
    private:
        T* ptr = nullptr;
        int* refcount = nullptr;

        void release(){
            if(refcount){
                --(*refcount);
                if(*refcount == 0){
                    delete ptr;
                    delete refcount;
                    cout << "DELETED"<<endl;
                }
            }
        }

    public:
        Sharedpointer(T *p=nullptr):ptr(p), refcount(nullptr){
            if(p){
                refcount = new int(1);
            }
        }
        Sharedpointer(Sharedpointer& other){
            ptr = other.ptr;
            refcount = other.refcount;
            ++(*refcount);
        }
        Sharedpointer& operator=(Sharedpointer& other){
            if(this != &other){
                release();
                ptr = other.ptr;
                refcount = other.refcount;
                ++(*refcount);
            }
            return *this;
        }

        ~Sharedpointer(){
            release();
        }

        T& operator *() const{return *ptr;};
        T* operator ->() const{return ptr;};

        int usecount() const{return refcount?*refcount:0;}

};

struct Data{
    int value;
    Data(int v):value(v){}
    ~Data(){}
};

int main(){
    Sharedpointer<Data> sptr(new Data(11));
    Sharedpointer<Data> sptr2 = sptr;
    cout<<"use count = "<< sptr.usecount()<<endl;
    cout<<"value = "<< sptr2->value<<endl;

    cout<<"use count = "<< sptr.usecount()<<endl;

}
