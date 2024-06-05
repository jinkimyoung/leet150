
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> minQ;
        unordered_map<int, vector<pair<int, int>>> adjs;
        unordered_set<int>      visit;
        int res = 0;

        for (auto e : times)
            adjs[e[0]].push_back({e[1], e[2]});  // {dst, signal}

        minQ.push({0, k});
        while (!minQ.empty())
        {
            int prevSignal = minQ.top().first, cur = minQ.top().second; // { time, dst } 
            minQ.pop();

            if (visit.find(cur) != visit.end())
                continue;
            visit.insert(cur);

            res = prevSignal;
            for (int i = 0; i < adjs[cur].size(); i++)
            {
                int dst = adjs[cur][i].first, curSignal = adjs[cur][i].second;

                if (visit.find(dst) != visit.end())
                    continue;                

                // target : [0], signal [1]
                minQ.push({prevSignal + curSignal, dst});
            }
        }
        return visit.size() == n ? res : -1;        
    }
};