
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, localArea;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    localArea = 0;
                    dfs(grid, i, j, m, n, localArea);
                    maxArea = max(maxArea, localArea);
                }

        return maxArea;
    }

    void dfs(vector<vector<int>> &g, int i, int j, int m, int n, int &maxArea)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return ;
        if (g[i][j] == 0)   return ;

        g[i][j] = 0;
        maxArea++;
        dfs(g, i+1, j, m, n, maxArea);
        dfs(g, i-1, j, m, n, maxArea);
        dfs(g, i, j+1, m, n, maxArea);
        dfs(g, i, j-1, m, n, maxArea);                        
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    ret = max(ret, dfs(grid, i, j, m, n));
        return ret;
    }

    int dfs(vector<vector<int>> &g, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (g[i][j] == 0)   return 0;
        g[i][j] = 0;

        return 1 + dfs(g, i+1, j, m, n) + dfs(g, i-1, j, m, n) \
                + dfs(g, i, j+1, m, n) + dfs(g, i, j-1, m, n);
    }
};
