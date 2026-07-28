#include <iostream>
using namespace std;


class MathUtils {
public:
    // Fully valid constexpr static member function
    constexpr int square(int x) const{
        return x * x;
    }
};

int main()
{
    constexpr MathUtils mathUtils; // Create a constexpr object
    constexpr int result = mathUtils.square(5);
    cout << result << endl;
    return 0;
}