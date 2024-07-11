
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> reqs; 
        unordered_set<int>  visit;

        for (auto e : prerequisites)
            reqs[e[0]].push_back(e[1]);
        
        for (int i = 0; i < numCourses; i++)
            if (!dfs(reqs, visit, i))
                return false;

        return true;
    }

    bool dfs(unordered_map<int, vector<int>> &reqs, unordered_set<int> &visit, int cur)
    {
        if (visit.find(cur) != visit.end()) return false;
        visit.insert(cur);

        for (int i = 0; i < reqs[cur].size(); i++)
        {
            if (!dfs(reqs, visit, reqs[cur][i]))
                return false;            
        }
        reqs[cur].clear();
        visit.erase(cur);

        return true;
    }
};

