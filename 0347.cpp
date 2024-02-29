
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <bits/stl_pair.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;

        for (int num : nums)
            mp[num]++;
        for (auto elem : mp)
            vec.push_back(pair(elem.first, elem.second));
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){ return a.second > b.second; });
        for (int i = 0; i < k; i++)
            ans.push_back(vec[i].first);

        return ans;
    }
};

// Using Priority Queue
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> list;
        priority_queue<pair<int,int>> sortedList;

        for(auto &num:nums){
            list[num]++;
        }

        for(auto iter=list.begin(); iter!=list.end();iter++){
            sortedList.push(make_pair(iter->second,iter->first));
        }

        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(sortedList.top().second);
            sortedList.pop();
        }
        return result;
    }
};
