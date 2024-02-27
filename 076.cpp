
// Time O(M+N), Space O(M+N)

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n)  return "";

        unordered_map<char, int> hm;
        for (char c : t)    hm[c]++;

        int sPos = -1, minLen = INT_MAX;
        for (int l = 0, r = 0, need = n; r < m; r++)
        {
            if (hm[s[r]] > 0)   need--;
            hm[s[r]]--;

            while (need == 0)
            {
                if (r - l + 1 < minLen)
                {
                    sPos = l;
                    minLen = r - l + 1;    
                }

                if (hm[s[l]] >= 0)  need++;
                hm[s[l++]]++;
            }
        }
        return sPos == -1 ? "" : s.substr(sPos, minLen);
    }
};