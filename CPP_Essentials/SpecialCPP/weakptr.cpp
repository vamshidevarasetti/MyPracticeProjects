#include <bits/stdc++.h>
using namespace std;

int main(){

    shared_ptr<int> sptr = make_shared<int>(42);
    weak_ptr<int> wp = sptr;

    cout<<"usecount: " << sptr.use_count()<<endl;

    if(auto spt = wp.lock()){
        cout<<*spt<<endl;
    }
    else{
        cout<<"object already destroyed"<<endl;
    }

    sptr.reset();
    if(auto spt = wp.lock()){
        cout<<*spt<<endl;
    }
    else{
        cout<<"object already destroyed"<<endl;
    }

    return 0;
}