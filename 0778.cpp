
#include <set>
#include <vector>
#include <priority_queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minH;
        set<pair<int, int>> visit;
        vector<vector<int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int n = grid.size();

        minH.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while (!minH.empty())
        {
            auto cur = minH.top();
            minH.pop();

            int t = cur[0], x = cur[1], y = cur[2];
            if ((x == n-1) && (y == n-1))
                return t;

            for (auto dir : directions)
            {
                int nx = x + dir[0], ny = y + dir[1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (visit.find({nx, ny}) != visit.end())
                    continue;
                
                visit.insert({nx, ny});
                minH.push({max(grid[nx][ny], t), nx, ny});
            }
        }
        return -1;
    }
};