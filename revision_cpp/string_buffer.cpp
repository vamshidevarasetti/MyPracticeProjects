#include <iostream> // Includes standard input/output stream library
#include <cstring>  // Includes C-string functions like strlen and strcpy

class StringBuffer {
private:
    char* data; // Pointer to store the dynamically allocated character array on the heap

public:
    // 1. Parameterized Constructor
    StringBuffer(const char* str = "") { // Accepts a C-string default parameter to handle empty strings
        if (str == nullptr) {            // Safety check for null pointer inputs
            data = new char[1];          // Allocate a minimal 1-byte buffer on the heap
            data[0] = '\0';              // Set it as a null-terminated empty string
        } else {
            data = new char[std::strlen(str) + 1]; // Allocate exact space required including the null terminator (\0)
            std::strcpy(data, str);      // Safely copy string characters from source buffer to heap block
        }
        std::cout << "Constructor: Allocated string at address " << static_cast<void*>(data) << "\n"; // Trace memory address
    }

    // 2. Copy Constructor (Deep Copy)
    StringBuffer(const StringBuffer& other) { // Takes the source object by const reference
        data = new char[std::strlen(other.data) + 1]; // Request a brand-new, independent memory block on the heap
        std::strcpy(data, other.data); // Physically copy the actual text values into the newly allocated block
        std::cout << "Copy Constructor: Deep copied string to new address " << static_cast<void*>(data) << "\n"; // Trace new memory address
    }

    // 3. Copy Assignment Operator (Deep Copy + Self-Assignment Protection)
    StringBuffer& operator=(const StringBuffer& other) { // Overloads the assignment symbol (=)
        if (this == &other) { // Guard condition: check if the object is being assigned to itself (e.g., obj1 = obj1)
            std::cout << "Assignment Operator: Self-assignment guarded. No work done.\n"; // Log protection trace
            return *this;     // Skip work and immediately return the current instance pointer
        }

        delete[] data; // Crucial Step: Deallocate existing heap memory first to avoid leaking memory slots

        data = new char[std::strlen(other.data) + 1]; // Request an entirely fresh heap memory region matching the new size
        std::strcpy(data, other.data); // Transfer text contents from the source string to the clean target address
        std::cout << "Assignment Operator: Reallocated and deep copied to " << static_cast<void*>(data) << "\n"; // Trace reallocation address
        
        return *this; // Return the current instance to enable chained assignments like (a = b = c)
    }

    // 4. Destructor
    ~StringBuffer() {
        std::cout << "Destructor: Freeing memory block from address " << static_cast<void*>(data) << "\n"; // Validation trace
        delete[] data; // Safely free the allocated character array buffer back to the operating system heap manager
    }

    // 5. Display Function
    void display() const { // Marked const because it reads the state without modifying member attributes
        std::cout << "Content: " << data << "\n-------------------------------------\n"; // Print the wrapped C-string array contents
    }
};

int main() {
    std::cout << "--- Initializing obj1 ---\n";
    StringBuffer obj1("Hello C++"); // Triggers parameterized constructor
    obj1.display();

    std::cout << "--- Initializing obj2 via Copy Constructor ---\n";
    StringBuffer obj2 = obj1;       // Triggers the deep copy constructor
    obj2.display();

    std::cout << "--- Testing Copy Assignment (obj2 = obj1) ---\n";
    StringBuffer obj3("Temporary Data"); // Creates another independent string block
    obj3 = obj1;                    // Triggers the deep copy assignment operator (safely clears "Temporary Data")
    obj3.display();

    std::cout << "--- Testing Self-Assignment Protection (obj1 = obj1) ---\n";
    obj1 = obj1;                    // Triggers assignment safety check without crashing or clearing its own memory

    std::cout << "--- Scope ending: Objects will be destroyed in reverse order ---\n";
    return 0;                       // Destructors release separate addresses automatically with zero double-free bugs
}