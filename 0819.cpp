#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int m = paragraph.length(), i = 0;
        unordered_map<string, int> mp;

        while (i < m)
        {
            while (i < m && paragraph[i] == ' ')
                i++;
            if (i == m) break;

            string s;
            while (i < m && isalpha(paragraph[i]))
                s += tolower(paragraph[i++]);
            i++;
            if (s.length() != 0) mp[s]++;
        }

        for (string b : banned)
            if (mp.find(b) != mp.end())
                mp.erase(b);
    
        string s;
        int count = INT_MIN;
        for (auto e : mp)
            if (count < e.second)
            {
                count = e.second;
                s = e.first;
            }

        return s;
    }
};
