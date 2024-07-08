

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26);
        for (int i = 0; i < s.length(); i++)
            lastIdx[s[i] - 'a'] = i;

        vector<int> ans;
        int size = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            size++;
            end = max(end, lastIdx[s[i] - 'a']);
            if (i == end)
            {
                ans.push_back(size);
                size = 0;
            } 
        }
        return ans;        
    }
};
