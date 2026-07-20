#include <iostream>
#include <string>

class Car {
    public:
        std::string brand;
        std::string speed;

        void display(){
            std::cout << "Brand: " << brand << std::endl;
            std::cout << "Speed: " << speed << std::endl;
        }

};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.speed = "120 km/h";

    car1.display();

    return 0;
}
