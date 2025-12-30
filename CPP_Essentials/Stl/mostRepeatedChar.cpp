#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	string str = "abrakadabraaaaaaBBBBBBBBBBBBBBBBBBBB2222222222222222222222222222222222222222";
    unordered_map<char, int> mymap = {};
    int max_count = 0;
    char most_char = 0;

    for (auto ch : str){
            if(isdigit(ch)){
            mymap[ch]++;

            if(mymap[ch]> max_count){
                max_count = mymap[ch];
                most_char = ch;
            }
        }
    }

    cout<<"charachter  " << most_char << "  repeated  "<< max_count<<" times"<<endl;

}