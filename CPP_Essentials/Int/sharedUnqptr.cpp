
#include <iostream>
#include <memory>

class A {
public:
    void display() {
        std::cout << "Function" << std::endl;
    }

    void functionone(std::unique_ptr<A> ptr1) {
        // Do something with ptr1
    }
};

int main() {
    std::shared_ptr<A> ptr = std::make_shared<A>();
    ptr->display();

    // Create a unique_ptr and pass it to functionone
    std::unique_ptr<A> uptr = std::make_unique<A>();
    ptr->functionone(std::move(uptr)); // ✅ move is required
}
