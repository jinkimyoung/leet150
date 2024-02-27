
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for (auto elem : mp)
            ans.push_back(elem.second);
        return ans;
    }
};

int main(void)
{
    return 0;
}