#include <iostream>
#include <thread>

using namespace std;

class Singleton{

    public:
        static Singleton* get_instance (){
            static Singleton instance;
            return &instance;
        }
        void do_something(){
            cout<<"Singleton instance address"<< this<<endl;
        }
        Singleton(const Singleton& ) = delete;
        Singleton operator=(const Singleton& ) = delete;
        Singleton(Singleton&& ) = delete;
        Singleton operator=(Singleton&& ) = delete;

    private:
        Singleton(){
            cout<<"inside constructor"<<endl;
        }

};



static void usesingleton(){
    Singleton::get_instance()->do_something();
}

int main(){

    Singleton *obj1 = Singleton::get_instance();
    Singleton *obj2 = Singleton::get_instance();

    if(obj1 == obj2){
        cout<<"pointing to same address"<<endl;
    }

    thread t1(usesingleton);
    thread t2(usesingleton);
    thread t3(usesingleton);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}