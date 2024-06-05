
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (vector<string> ticket : tickets)
            m[ticket[0]].insert(ticket[1]);

        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(unordered_map<string, multiset<string>> &m, string airport, vector<string> &result)
    {
        while (!m[airport].empty())
        {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(m, next, result);
        }
        result.push_back(airport);
    }
};