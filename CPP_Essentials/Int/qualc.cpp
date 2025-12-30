#include <iostream>
#include <memory>
#include <functional>

// Employee structure
typedef struct Emp {
    std::string name; // Use std::string for safety
    int id;
} Emp;

// Class for initializing and invoking a callback
class Init {
public:
    void init(std::shared_ptr<Emp> emp, std::function<void(std::shared_ptr<Emp>)> callback) {
        // Some initialization logic could go here
        callback(emp); // Invoke the callback
    }
};

// Class for printing
class Print {
public:
    void print(std::shared_ptr<Emp> emp) {
        std::cout << "Employee Name: " << emp->name << "\n";
        std::cout << "Employee ID: " << emp->id << "\n";
    }
};

int main() {
    // Create a shared pointer for Emp
    auto emp = std::make_shared<Emp>();
    emp->name = "Alice";
    emp->id = 101;

    // Create instances of Init and Print
    Init initializer;
    Print printer;

    // Pass printer.print as a callback using a lambda
    initializer.init(emp, [&](std::shared_ptr<Emp> e) {
        printer.print(e);
    });

    // The shared pointer ensures emp's lifetime covers all uses
    return 0;
}
