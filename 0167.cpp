
#include <vector>
using namespace std;

// Two Pointers is possible with sorted array.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;

        while (l < r)
        {
            sum = numbers[l] + numbers[r];
            if (sum == target)  return { l+1, r+1 };
            else if (sum > target)  r = r - 1;
            else if (sum < target)  l = l + 1;
        }
        return {};
    }
};


// HashMap

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < numbers.size(); i++)
        {
            int oShift  = 1001 + numbers[i];
            int lShift = target - numbers[i] + 1001;
    
            if (mp.find(lShift) != mp.end())
                return { mp[lShift]+1, i+1 };
            mp[oShift] = i;
        }
        return {};
    }
};
