#include <iostream>

// A constexpr function to compute square of a number
constexpr int square(int x) {
    return x * x;
}

int main() {
    // Compile-time evaluation
    constexpr int value = square(5);  // Computed at compile time

    // Runtime evaluation (input is not known at compile time)
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    int result = square(num); // Computed at runtime

    std::cout << "Square of 5 (compile-time) = " << value << "\n";
    std::cout << "Square of " << num << " (runtime) = " << result << "\n";
}
