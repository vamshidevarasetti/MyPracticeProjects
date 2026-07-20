// Remove this:
// #include <pthread.h>

// Add this:
#include <thread>
#include <iostream>

void printHello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    // Create and start a thread
    std::thread t1(printHello);
    
    // Wait for the thread to finish
    t1.join(); 
    return 0;
}