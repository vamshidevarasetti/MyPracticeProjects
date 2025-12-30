#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    std::string arr[] = {"apple", "banana", "apple", "orange", "banana", "apple"};
    
    int n = sizeof(arr)/sizeof(arr[0]);

    std::string mostFrequent;
    std::unordered_map <std::string, int> freq;
    int maxcount =0;

    for (int i=0;i<n;i++)
    {
        freq[arr[i]]++;

        if(freq[arr[i]] > maxcount)
        {
            maxcount = freq[arr[i]];
            mostFrequent = arr[i];
        }
    }

    // 🔍 Print the frequency of each string in the map
    std::cout << "\nString Frequencies:\n";
    for(const auto& data: freq)
    {
        cout << data.first << " = " << data.second<<endl;
    }

    std::cout << "\nMost repeated string: " << mostFrequent
              << " (occurred " << maxcount << " times)" << std::endl;

    return 0;
}
