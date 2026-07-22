#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1 = "Modern c++";
    string s2 = move(s1);
    cout << "s1: " << s1 << endl; // s1 is now in a valid but unspecified state
    cout << "s2: " << s2 << endl; // s2 now owns the contents of s1
    s1 = "hello again";
    cout << "s1: " << s1 << endl; // s1 is now in a valid but unspecified state
    cout << "s2: " << s2 << endl; // s2 now owns the contents of s1
    return 0;
}