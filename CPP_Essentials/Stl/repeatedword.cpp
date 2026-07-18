#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    string str = "in a building in a room in a house in";
    unordered_map<string, int> wordmap;
    string word;
    int maxcount =0;
    string mostfreq;
    stringstream ss(str);
    while (ss >> word){
        wordmap[word]++;
    }

    for(const auto& pair:wordmap){
        if(pair.second > maxcount);
        maxcount = pair.second;
        mostfreq = pair.first;
    }
    cout<<"max repeated word is: "<< mostfreq <<endl <<"Repeated " << maxcount<<" number of times"<<endl;
}

/*int main(){
    string str = "in a building in a room in a house in";
    unordered_map<string, int> wordmap;
    int maxcount =0;
    string maxchar = "";
    vector<string> vecwords;
    string word;
    stringstream ss(str);
    while (ss >> word){
        vecwords.push_back(word);
    }

    for(const auto & words : vecwords)
    {
        cout<<words<<endl;
    }
    for(int i=0;i<vecwords.size(); i++){
        wordmap[vecwords[i]]++;

        if(wordmap[vecwords[i]] > maxcount){
            maxcount = wordmap[vecwords[i]];
            maxchar = vecwords[i];
        }
    }
    cout<<"max repeated word is: "<< maxchar <<endl <<"Repeated " << maxcount<<" number of times"<<endl;

}*/