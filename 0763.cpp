

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n = s.length(), pos[26] = {0};

        for (int i = 0; i < n; i++)
            pos[s[i]-'a'] = i;
        
        int end = 0, size = 0;
        for (int i = 0; i < n; i++)
        {
            size++;
            end = max(end, pos[s[i]-'a']);
            if (end == i)
            {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;        
    }
};