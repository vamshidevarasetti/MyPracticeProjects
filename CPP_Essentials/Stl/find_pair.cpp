#include<iostream>
#include<unordered_map>
using namespace std;

void findpair(int nums[], int n, int target){
    unordered_map<int, int> map;
    for(int i=0;i<n; ++i){
        if(map.find(target - nums[i]) != map.end())
        {
            cout<<"pair found ("<< nums[map[target-nums[i]]] << ", "<<nums[i]<<")"<<endl;
        }

        map[nums[i]] = i;
    }
    
}

int main(){
    int nums[] = {8,7,2,5,3,1};
    int target = 10;

    int n = sizeof(nums)/sizeof(nums[0]);

    findpair(nums, n, target);
    return 0;
}

