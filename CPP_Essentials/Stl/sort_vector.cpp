//Remove Duplicates and sort vector

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    vector<string> str = {"eat", "sleep", "repeat", "eat", "sleep", "repeat"};
    sort(str.begin(), str.end());
    std::cout << "\nAfter sort:\n";
    for (const auto& w : str) std::cout << w << " ";
    std::cout << "\n";
    auto last = unique(str.begin(), str.end());
    std::cout << "\nAfter unique (before erase):\n";
    for (const auto& w : str) std::cout << w << " ";
    std::cout << "\n";
    str.erase(last, str.end());
    std::cout << "\nFinal result:\n";
    for(const auto& s:str){cout<<s<<" ";}
    std::cout << "\n";
    return 0;

}