#include <iostream>
using namespace std;

class Singleton {
public:
    static Singleton* get_instance() {
        static Singleton instance; // Thread-safe in C++11+
        return &instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;
    Singleton& operator=(const Singleton&&) = delete;

private:
    Singleton() { cout << "singleton class" << endl; }
};

int main() {
    Singleton* obj1 = Singleton::get_instance();
    Singleton* obj2 = Singleton::get_instance();

    if (obj1 == obj2) {
        cout << "pointing to same instance" << endl;
    }
}


/*#include <iostream>

using namespace std;

class Singleton{
    public:
        static Singleton* get_instance(){
            static Singleton instance;
            return &instance;
        }

        Singleton(const Singleton& ) = delete;
        Singleton& operator=(const Singleton& ) = delete;

    private:
        Singleton(){ cout <<"singleton class"<<endl;}
};

int main()
{
    Singleton *obj1 = Singleton::get_instance();
    Singleton *obj2 = Singleton::get_instance();

    if(obj1 == obj2)
    {
        cout <<"pointing to same instance"<<endl;
    }

}*/