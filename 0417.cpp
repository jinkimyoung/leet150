
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n-1, m, n);            
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m-1, j, m, n);            
        }     

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)                   
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
        return ans;
    }

    void dfs(vector<vector<int>> &h, vector<vector<bool>> &b, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return ;
        if (b[i][j])    return ;

        b[i][j] = true;
        if (i > 0 && h[i][j] <= h[i-1][j])      dfs(h, b, i-1, j, m, n);
        if (i < m-1 && h[i][j] <= h[i+1][j])    dfs(h, b, i+1, j, m, n);
        if (j > 0 && h[i][j] <= h[i][j-1])      dfs(h, b, i, j-1, m, n);
        if (j < n-1 && h[i][j] <= h[i][j+1])    dfs(h, b, i, j+1, m, n);        
    }
};