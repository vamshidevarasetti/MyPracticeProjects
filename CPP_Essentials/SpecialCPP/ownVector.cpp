#include<iostream>

class vectorclass{
    int * arr;
    int capacity;
    int current;

    public:
        vectorclass(){
            arr = new int;
            capacity =1;
            current =0;
        }
        ~vectorclass(){
            delete []arr;
        }

        void push(int value){
            if(current == capacity){
                int* temp = new int[2* capacity];
                
                for(int i=0; i<capacity; i++){
                    temp[i] = arr[i];
                }
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }

            arr[current++] = value;
        }

        int pop(){

            if(current > 0){
                current--;
            }
        }
        int size(){
            return current;
        }

        int getcapacity(){
            return capacity;
        }

        void print(){
            for(int i=0;i<current;i++)
            {
                std::cout<<arr[i]<<" "<<std::endl;
            }
        }

};

int main() {
    vectorclass v;
    v.push(10);
    v.push(20);
    v.push(30);
    v.print();            // Output: 10 20 30
    v.pop();
    v.print();            // Output: 10 20
    std::cout << v.size() << std::endl;         // Output: 2
    std::cout << v.getcapacity() << std::endl;  // Output: current capacity, e.g. 4

    return 0;
}