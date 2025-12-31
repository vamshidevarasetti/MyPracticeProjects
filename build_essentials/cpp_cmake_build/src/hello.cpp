#include <iostream>
#include "hello.h"
#include "ext.h"

void say_hello() {
    std::cout << "Hello from cmake with libraries " << std::endl;
}

int main(){
    say_hello();
    ext_function();
    return 0;
}