#include <iostream>
#include <memory_resource>
#include <vector>

/*int main() {
    char buffer[1024];
    std::pmr::monotonic_buffer_resource resource{buffer, sizeof(buffer)};
    std::pmr::vector<int> vec{&resource};

    vec.push_back(42);
    std::cout << vec[0] << "\n";

    return 0;
}*/

int main() {
    // Step 1: Create a buffer for monotonic allocation
    constexpr std::size_t bufferSize = 1024;
    char buffer[bufferSize];

    // Step 2: Create a monotonic_buffer_resource using the buffer
    std::pmr::monotonic_buffer_resource resource{buffer, sizeof(buffer)};

    // Step 3: Create a vector that uses this memory resource
    std::pmr::vector<int> vec{&resource};

    // Step 4: Use the vector like normal
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // Step 5: Print the contents
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 0;
}
