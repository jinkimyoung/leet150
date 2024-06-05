
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> reqs;
        unordered_set<int>      takes;

        for (auto pre : prerequisites)
            reqs[pre[0]].push_back(pre[1]);

        for (int i = 0; i < numCourses; i++)
            if (!dfs(reqs, takes, i))
                return false;
        return true;
    }

    bool dfs(unordered_map<int, vector<int>> &reqs, unordered_set<int> &takes, int course)
    {
        if (takes.find(course) != takes.end())  return false;
        if (reqs[course].empty())   return true;

        takes.insert(course);
        for (int i = 0; i < reqs[course].size(); i++)
        {
            int nextCourse = reqs[course][i];
            if (!dfs(reqs, takes, nextCourse))
                return false;
        }
        takes.erase(course);
        reqs[course].clear();
        return true;
    }

};