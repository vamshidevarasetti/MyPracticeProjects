#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int limit = 4;
	// auto sum = [](int a , int b)
	// {
	// 	return a+ b;
	// };
	// cout << sum(2,3)<<endl;
    vector<int> nums = {9,3,5,1,6,2, 4, 8, 7};
	sort(nums.begin(), nums.end(), [](int a, int b)
	{
		return a>b;
	});
    // for_each(nums.begin(), nums.end(), [](int i)
	// {
    //     if(i%2 == 0)
    //     {
    //         cout << i << " ";
    //     }
	// });
    for_each(nums.begin(), nums.end(), [limit](int i)
	{
        if(i > limit)
        {
            cout << i << " ";
        }
	});

    // int count = count_if(nums.begin(), nums.end(), [](int i)
    // {
    //     return i > 5;
    // });

	// for (const auto& i : nums)
	// {
	// 	cout<< i << " ";
	// }

	//cout<<count<<endl;
    cout << endl;

	return 0;
}