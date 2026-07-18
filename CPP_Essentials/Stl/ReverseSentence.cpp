#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str = "I am vamshi in the home";
    vector<string> vec;

    stringstream ss(str);
    string word;
    while (ss >> word){
        vec.push_back(word);
    }
    reverse(vec.begin(), vec.end());

    for(auto v :vec)
    {
        cout << v << " ";
    }
    return 0;
}