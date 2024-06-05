
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>>   q;
        int total = 0, times = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)    q.push({i, j});
                if (grid[i][j] != 0)    total++;
            }

        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        while (!q.empty())
        {
            int rotten = q.size();
            total -= rotten;

            for (int i = 0; i < rotten; i++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] != 1) continue;

                    grid[nx][ny] = 2;
                    q.push({nx, ny});    
                }
            }
            if (!q.empty()) times++;    // to cover when there are only rotten
        }
        return total != 0 ? -1 : times;
    }
};