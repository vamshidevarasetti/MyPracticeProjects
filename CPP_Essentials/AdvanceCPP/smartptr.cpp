#include <iostream>  

#include <memory> 

  

using namespace std;  

class Rectangle {  

    int length; 

    int breadth; 

public: 

    Rectangle(int l, int b){ 

        length = l; 

        breadth = b; 

    } 

    int area() 

    { 

        return length * breadth; 

    } 

}; 

int main(){ 

    //unique_ptr<Rectangle> P1(new Rectangle(10, 5)); 
    auto ptr = make_unique<Rectangle>(10,5);

    std::cout<< ptr->area() << std::endl; 

    shared_ptr<Rectangle> P2 = std::move(ptr); 

    std::cout<< P2->area() << std::endl; 

    return 0; 

}