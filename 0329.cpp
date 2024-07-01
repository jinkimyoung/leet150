
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, i, j, dp, dirs));
        return ans;
    }

    int dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &dp, vector<vector<int>>& dirs)
    {
        if (dp[x][y] != 0) return dp[x][y];

        int res = 1;
        for (auto dir : dirs)
        {
            int nx = dir[0] + x;
            int ny = dir[1] + y;
            if (nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size()) continue;
            if (matrix[x][y] >= matrix[nx][ny])  continue;

            res = max(res, 1 + dfs(matrix, nx, ny, dp, dirs));
        }
        dp[x][y] = res;
        return res;
    }
};

