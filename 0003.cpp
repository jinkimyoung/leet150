
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, l = 0, r = 0;

        for (r = 0; r < s.length(); r++)
        {
            l = max(l, mp[s[r]]);
            ans = max(ans, r - l + 1);
            mp[s[r]] = r + 1;
        }        
        return ans;
    }
};

