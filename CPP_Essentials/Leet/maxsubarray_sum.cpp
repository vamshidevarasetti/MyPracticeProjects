#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, windowSum = 0;
        int distinct = 0;
        unordered_map<int, int> count;

        for (int i = 0; i < nums.size(); ++i) {
            windowSum += nums[i];
            if (++count[nums[i]] == 1) {
                ++distinct;
            }

            if (i >= k) {
                if (--count[nums[i - k]] == 0) {
                    --distinct;
                }
                windowSum -= nums[i - k];
            }

            if (i >= k - 1 && distinct == k) {
                ans = max(ans, windowSum);
            }
            
            cout << nums[i]<< " = " << count[nums[i]] <<endl;
            cout << " windowSum " << windowSum <<endl;
        }

        return ans;
    }
};

int main() {
	vector<int> nums = {1,3,4,5,9,9,9};
	int k =3;
	Solution obj;
	cout<<obj.maximumSubarraySum(nums,3)<<endl;
}
