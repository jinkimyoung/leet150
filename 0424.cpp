
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxF = 0, l, r;
        unordered_map<char, int> m;
        
        for (l = 0, r = 0; r < s.length(); r++)
        {
            m[s[r]]++;
            maxF = max(m[s[r]], maxF);
            if ((r - l + 1) > (maxF + k))
            {
                m[s[l]]--;
                l++;
            }
            else
            {
                ans = max(ans, (r - l + 1));
            }
        }
        return ans;
    }
};

