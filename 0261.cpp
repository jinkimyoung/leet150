#include <vector>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool>    visited(n, false);

        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        if (cycle(adj, visited, -1, 0))
            return false;
            
        for (int i = 0; i < n; i++)
            if (!visited[i])
                return false;
        
        return true;
    }

    bool cycle(vector<vector<int>> &adj, vector<bool> &visited, int parent, int cur)
    {
        if (visited[cur]) return true;
        visited[cur] = true;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int child = adj[cur][i];
            if (parent != child && cycle(adj, visited, cur, child))
                return true;
        }
        return false;
    }
};