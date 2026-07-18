#include <iostream>
using namespace std;

int main(){
    int arr[6] = {3,5,1,8,13};

    int i,n,sum, l=0,r=0;
    int req_sum = 14;

    sum = arr[0];
    n = sizeof(arr);

    while ( (r < n) )
    {
        if(sum == req_sum)
            break;
        else if(sum < req_sum)
        {
            r++;
            sum += arr[r];
        }
        else{
            sum -= arr[l];
            l++;
        }
        
    }
        if(r<n)
        {
            cout << l<< " "<<r<<endl;
            cout<<"sum = "<< sum<<endl;
        }
        else{
            cout << l<< " "<<r<<endl;
            cout<<"sum = "<< sum<<endl;
            cout<<-1<<endl;
        }
    return 0;
}
