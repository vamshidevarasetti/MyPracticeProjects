#include<iostream>

/*template<typename T>
class UniquePtr {
private:
    T* ptr;

public:
    // Constructor
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePtr() {
        delete ptr;
    }

    // Move Constructor
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move Assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Deleted Copy Constructor and Assignment
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Accessors
    T* get() const { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    // Reset
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }

    // Release ownership
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};


struct Sensor {
    void read() { std::cout << "Reading sensor...\n"; }
};

int main() {
    UniquePtr<Sensor> sensor(new Sensor);
    sensor->read();

    UniquePtr<Sensor> moved = std::move(sensor);  // Ownership transferred
    if (!sensor.get()) std::cout << "Sensor moved\n";

    return 0;
}*/


template<typename T>
class uniqueptr{

    private:
     T*ptr;

    public:
        uniqueptr(T* p = nullptr):ptr(p){};
        ~uniqueptr(){delete ptr;}

        //move constructor
         uniqueptr(uniqueptr&& other){
            ptr = other.ptr;
            other.ptr = nullptr;
         }
        //move assignment operator
        uniqueptr& operator=(uniqueptr&& other){
            if(this!= other){
                delete ptr;
                ptr = other.ptr;
                other.ptr=nullptr;
            }
            return *this;
        }

        //delete copy con and copy assginment 

        uniqueptr(const uniqueptr&) = delete;
        uniqueptr& operator=(const uniqueptr&) = delete;

        //accesors
        T* get(){return ptr;}
        T& operator*()const {return *ptr;}
        T* operator->()const {return ptr;}

        //reset

        void reset(T* p = nullptr){
            delete ptr;
            ptr = p;
        }

        //release ownership
        T* release(){
            T* temp = ptr;
            ptr = nullptr;
            return temp;
        }

};

struct sensor{
    void read() {std::cout<<"reading sensor"<<std::endl;}
};

int main()
{
    uniqueptr<sensor> uptr;
    uptr->read();

    uniqueptr<sensor> uptr2 = std::move(uptr);
    uptr2->read();

    if(!uptr.get()){std::cout << "uptr moved"<<std::endl;}

    return 0;

}