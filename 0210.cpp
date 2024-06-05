
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> reqs;
        unordered_set<int>              visit, cycle;
        vector<int>                     seq;

        for (auto pre : prerequisites)
            reqs[pre[0]].push_back(pre[1]);

        for (int course = 0; course < numCourses; course++)
            if (!dfs(reqs, visit, cycle, seq, course))
                return {};
        return seq;
    }

    bool dfs(unordered_map<int, vector<int>> &reqs, unordered_set<int> &visit, unordered_set<int> &cycle, \
             vector<int> &seq, int course)
    {
        if (cycle.find(course) != cycle.end())  return false;
        if (visit.find(course) != visit.end())  return true;

        cycle.insert(course);
        for (int i = 0; i < reqs[course].size(); i++)
        {
            int nextCourse = reqs[course][i];
            if (!dfs(reqs, visit, cycle, seq, nextCourse))
                return false;
        }
        cycle.erase(course);
        visit.insert(course);
        seq.push_back(course);
        return true;
    }
};