#include <iostream> 
#include <functional> 


// Define a functor 
template <typename T> 
struct MultiplyByTen { 
    T factor; 
    MultiplyByTen(T f): factor(f){} 
    T operator()(T x) { 
        return x*factor; 
    } 
}; 

int multiply(int x, int factor){ 
    return x*factor; 
} 

int main() { 
    std::function<int(int)> multiplyByTen = MultiplyByTen{10}; //functor 
    std::cout << multiplyByTen(20) << std::endl; 

    std::function<int(int)> multiplybyfive = [](int x){return x*5;}; //lambda 
    std::cout << multiplybyfive(20) << std::endl; 

    std::function<int(int, int)> multiplyby = multiply;  //function pointers 
    std::cout << multiplyby(50, 50) << std::endl; 

} 