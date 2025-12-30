#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str = "z i am vamshi in the office";

    //for(auto itr = str.begin(); itr!= str.end(); ++itr)
    for(auto itr : str)
    {
        char current_char = itr;
        int count =0;

        for (auto ch: str)
        {
            if(ch ==  current_char)
            {
                count++;
            }
        }
        if(count == 1)
        {
            cout <<"current char : "<<current_char<<endl;
            return 0;
        }
    
    }
    return 0;
}