#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class vector{
    private:
        T* data = nullptr;
        size_t capacity =0;
        size_t size =0;

    void resize(size_t newcapacity){
        T* newdata = new T[newcapacity];
        for(size_t i=0; i<size; i++){
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
        capacity = newcapacity;
    }

    public:
        vector(size_t initcapacity = 4):capacity(initcapacity), size(0){
            data = new T[capacity];
        }

        vector(vector& other){
            data = new T[capacity];
            capacity = other.capacity;
            size = other.size;
            for(size_t i=0; i<size; i++){
                data[i] = other.data[i];
            }
        }

        vector& operator=(const vector& other){
            if(*this != other){
                delete[] data;
                data = new T[capacity];
                capacity = other.capacity;
                size = other.size;
                for(size_t i=0; i<size; i++){
                    data[i] = other.data[i];
                }
            }
            return *this;
            
        }
        void push_back(const T& value){
            if(size == capacity){
                resize(capacity *2);
            }
            data[size++] = value;
        }
        
        T& operator[](size_t index){
            if(index > size){
                throw std::out_of_range("index out of bounds");
            }
            return data[index];
        }

        const T& operator[](size_t index)const{
            if(index > size){
                throw out_of_range("index out of bounds");
            }
            return data[index];
        }
        size_t get_size() const {return size;}
        size_t get_capacity() const {return capacity;}

};

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (size_t i = 0; i < v.get_size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";

    vector<int> v2 = v;  // Copy constructor
    v2.push_back(40);

    for (size_t i = 0; i < v2.get_size(); ++i)
        std::cout << v2[i] << " ";
    std::cout << "\n";
}