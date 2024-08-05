

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        vector<int> res;

        for (int i = 0; i < s.length(); i++)
            mp[s[i]] = i;

        for (int end = 0, size = 0, i = 0; i < s.length(); i++)
        {
            size++;
            end = max(end, mp[s[i]]);
            if (end == i)
            {
                res.push_back(size);
                size = 0;
            }
        }
        return res;
    }
};

