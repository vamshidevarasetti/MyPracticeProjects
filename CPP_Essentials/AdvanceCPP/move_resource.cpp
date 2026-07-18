#include <iostream>
#include <string>

class LoggableResource {
private:
    std::string name;

public:
    // Constructor
    LoggableResource(const std::string& n) : name(n) {
        std::cout << "[Construct] " << name << "\n";
    }

    // Copy Constructor
    LoggableResource(const LoggableResource& other) : name(other.name) {
        std::cout << "[Copy] " << name << "\n";
    }

    // Move Constructor
    LoggableResource(LoggableResource&& other) noexcept
        : name(std::move(other.name)) {
        std::cout << "[Move Construct] from " << other.name << "\n";
    }

    // Copy Assignment
    LoggableResource& operator=(const LoggableResource& other) {
        std::cout << "[Copy Assign] " << other.name << " to " << name << "\n";
        if (this != &other) {
            name = other.name;
        }
        return *this;
    }

    // Move Assignment
    LoggableResource& operator=(LoggableResource&& other) noexcept {
        std::cout << "[Move Assign] from " << other.name << " to " << name << "\n";
        if (this != &other) {
            name = std::move(other.name); 
            other.name = "<moved-from>";
        }
        return *this;
    }

    // Destructor
    ~LoggableResource() {
        std::cout << "[Destruct] " << name << "\n";
    }
};


int main() {
    LoggableResource r1("Alpha");
    LoggableResource r2 = std::move(r1);  // Move constructor
    LoggableResource r3("Gamma");
    r3 = std::move(r2);                   // Move assignment
}
