#include <bits/stdc++.h>
using namespace std;
#include <string>

void printvec(vector<int>& vec){
    for (size_t i = 0; i < vec.size(); ++i) {
        if(vec[i] != -1){
            cout << "Index: " << char('A' + i) << ", Value: " << vec[i] << endl;
        }
    }
    cout<<endl;
}

int longsubstring(string str){

    vector<int> vec(256, -1);
    //printvec(vec);
    int start =-1;
    int maxlen = 0;

    for(int i=0; i<str.size(); ++i){
        if(vec[str[i]] > start)
            start = vec[str[i]];
        vec[str[i]] = i;
        cout << "maxlen before ="<<maxlen<<endl;
        maxlen = max(maxlen, i-start);
        cout << "i ="<<i<<endl;
        cout << "start ="<<start<<endl;
        cout << "vec["<<str[i]<<"]="<<vec[str[i]]<<endl;
        //cout << "str[i] ="<<str[i]<<endl;
        cout << "i-start ="<<i-start<<endl;
        cout << "maxlen after ="<<maxlen<<endl;
        cout<<endl;
    }
    printvec(vec);
    return maxlen;
}

int main(){
    string str = "pwwkew";

    int result = longsubstring(str);
    cout<< "max len substring : "<< result<<endl;
}