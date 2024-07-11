#include <vector>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int nx, ny, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        
        vector<vector<int>> total(m, vector<int>(n, 0));
        int minDist = INT_MAX, emptyLandValue = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    minDist = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    int steps = 0;
                    while (!q.empty())
                    {
                        steps++;
                        for (int l = q.size(); l > 0; l--)
                        {
                            int x = q.front().first, y = q.front().second;
                            q.pop();
                            for (int k = 0; k < 4; k++)
                            {
                                nx = x + dx[k];
                                ny = y + dy[k];
                                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                                if (grid[nx][ny] == emptyLandValue)
                                {
                                    grid[nx][ny]--;
                                    total[nx][ny] += steps;      
                                    q.push({nx, ny});
                                    minDist = min(minDist, total[nx][ny]);                  
                                }
                            }
                        }
                    }
                    // Decrement empty land value to be searched in next iteration.
                    emptyLandValue--;                    
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
};