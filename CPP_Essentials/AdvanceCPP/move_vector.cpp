#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v){
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <typename T>
void swap(T&a, T&b){
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

int main(){

    vector<int> v1;
    vector<int> v2;

    for(int i=0; i<5; ++i){
        v1.push_back(i);
    }
    for(int i=10; i<17; ++i){
        v2.push_back(i);
    }

    print_vector(v1);
    print_vector(v2);

    swap(v1, v2);

    print_vector(v1);
    print_vector(v2);

    return 0;
}