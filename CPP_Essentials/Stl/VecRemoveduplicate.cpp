#include<iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    std::vector<int> vec = {1, 11, 3, 2, 3, 2, 4, 1, 5, 3};

    /*for(int i=0; i<sizeof(vec); i++){
        vec.erase(remove(vec.begin()+i+1, vec.end(), vec[i]), vec.end());
    }
    for(auto v:vec){
        cout<<v<<endl;
    }*/

    std::unordered_set<int> result(vec.begin(), vec.end());

    for (auto val: result){
        cout<< val<<endl;
    }
    return 0;

}