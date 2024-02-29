
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int num : nums)
        {
            s.insert(num);
        }
        return s.size() < nums.size();
    }
};


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> m;
        for (int num : nums)
        {
            if (m[num])
                return true;
            m[num] = 1;
        }
        return false;
    }
};