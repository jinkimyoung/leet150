
// Coloring by DFS
#include <vector>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                stack<int> stk;
                stk.push(i);
                color[i] = 0;

                while (!stk.empty())
                {
                    int node = stk.top();
                    stk.pop();

                    for (int neigh : graph[node])
                    {
                        if (color[neigh] == -1)
                        {
                            stk.push(neigh);
                            color[neigh] = color[node] ^ 0x1;                            
                        }
                        else if (color[node] == color[neigh])
                            return false;
                    }
                }
            }
        }
        return true;      
    }
};