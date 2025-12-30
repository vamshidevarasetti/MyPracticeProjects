#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;

int do_calc(int x)
{
    this_thread::sleep_for(chrono::seconds(3));
    return x*x;
}

int main(){

    future<int> result = async(launch::async, do_calc, 10);

    int final_result = result.get();

    cout<<"final_result :" << final_result<<endl;

    return 0;
}











/*#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// A function that takes some time to compute
int longComputation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return x * x;
}

int main() {
    // Launch longComputation asynchronously
    std::future<int> result = std::async(std::launch::async, longComputation, 12);

    // Do other work while waiting
    std::cout << "Computation running... do something else!\n";

    // Wait for the result
    int value = result.get();
    std::cout << "Result is: " << value << std::endl;
    return 0;
}*/
