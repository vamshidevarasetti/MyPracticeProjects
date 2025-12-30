#include <iostream>
#include <type_traits>
#include <string>

using namespace std;

//Numeric multiplication
template <typename T1, typename T2>
auto Multiply(T1 a, T2 b) -> typename enable_if<is_arithmetic<T1>::value && is_arithmetic<T2>::value, decltype(a*b)>::type
{
    return a * b;
}

//String repetation
template <typename T1, typename T2>
auto Multiply(T1 str, T2 times) -> typename enable_if<is_same<string, T1>::value && is_integral<T2>::value, string>::type
{
    string result;
    for (int i=0;i<times; i++){
        result += str;
    }
    return result;
}

int main()
{
    cout<<Multiply(5 ,3)<<endl;
    cout<<Multiply(string("Vamshi ") ,3)<<endl;
}