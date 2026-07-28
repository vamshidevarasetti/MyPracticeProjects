#include <iostream>
#include <utility>
using namespace std;

void test(int&)
{
    cout << "Lvalue\n";
}

void test(int&&)
{
    cout << "Rvalue\n";
}

template<typename T>
void wrapper(T&& value)
{
    test(std::forward<T>(value));
    //test(std::move(value));
}

int main()
{
    int x = 10;

    wrapper(x);

    wrapper(20);
}

// #include <iostream>
// #include <utility>
// using namespace std;

// void process(string&)
// {
//     cout << "Lvalue reference processed" << endl;
// }

// void process(string&&)
// {
//     cout << "Rvalue reference processed" << endl;
// }

// template <typename T>
// void forward(T&& arg)
// {
//     //process(forward<T>(arg));  // Perfect forwarding
//     process(move(arg));  // Move semantics
// }

// int main()
// {
//     string str = "Hello";
//     process(str);          // Calls lvalue reference
//     process(string("World"));      // Calls rvalue reference

//     return 0;
// }