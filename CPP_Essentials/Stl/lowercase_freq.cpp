#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str = "abrakadabra";
	int freq[26] = {0};
	for(char i : str)
	{
		if(i >= 'a' && i <='z')
		{
			freq[i-'a']++;
		}
	}
	for(int i = 0 ; i <26 ; i++)
	{
		if(freq[i]>0)
		{
			std::cout << char('a' + i) << "  "<< freq[i] << std::endl;
		}
	}

}