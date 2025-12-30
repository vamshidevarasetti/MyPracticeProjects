#include<iostream>
#include<string>
#include<map>
using namespace std;
 
int main()
{
	string str = "Rajeshrajeshboga";
	map<char, int> freq;
	for(char ch : str)
	{
		if(ch >= 'a' && ch <= 'z')
		{
			freq[ch]++;
		}
	}
 
	for(auto i : freq)
	{
		std::cout << i.first<< " = " <<i.second<< std::endl;
 
	}
 
 
}