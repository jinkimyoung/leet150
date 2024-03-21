
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        vector<pair<double, pair<int, int>>> list;

        for (auto position : points)
        {
            double dis = position[0] * position[0] + position[1] * position[1];
            list.push_back({dis, {position[0], position[1]}});
        }
        sort(list.begin(), list.end(), [](auto &a, auto &b) { return a.first < b.first; } );
        for (int i = 0; i < k; i++)
            ans.push_back({list[i].second.first, list[i].second.second});

        return ans;
    }
};

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for (auto& p : points)
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        // Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> res;
        while (k--){
            vector<int> el = pq.top();
            pq.pop();
            res.push_back({el[1], el[2]});
        }
        return res;
    }
};

