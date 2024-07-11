


#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int>mp;
        int i = 0;
        int ans =0;
        for(int j = 0; j < s.size(); j++)
        {
            mp[s[j]]++;
            while(mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
