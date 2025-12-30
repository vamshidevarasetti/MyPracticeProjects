#include<iostream>
#include <string>
#include <vector>
using namespace std;

bool isRotate(string &a, string &b){
    if(a.size() != b.size()) 
        return false;

    return (a+a).find(b) != string::npos;
}

int main() {
    vector<bool> result;
    struct { string a, b; } tests[] = {
        {"waterbottle", "erbottlewat"}, // true
        {"aaaa",        "aaaa"},        // true
        {"abcde",       "cdeab"},       // true
        {"abcde",       "abced"},       // false
        {"",            ""},            // true
        {"ab",          "a"},           // false (len mismatch)
        {"abc",         "cab"},         // true
    };

    for(auto&t : tests)
    {
        result.push_back(isRotate(t.a, t.b));
    }
    for(auto v: result){
        cout<< boolalpha << v <<endl;
    }

}