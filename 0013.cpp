
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        std::unordered_map<char, int> mp = { \
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, \
            {'C', 100}, {'D', 500}, {'M', 1000} };
        int i, n = s.length() - 1, ans = 0;

        ans = mp[s[n]];
        for (i = n; i >= 1; i--)
        {
            if (mp[s[i-1]] < mp[s[i]])
                ans = ans - mp[s[i-1]];
            else
                ans = ans + mp[s[i-1]];
        } 

        return ans;
    }
};
