

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<pair<int,int>> delta = {{1,0},{-1,0},{0,1},{0,-1}};
        int m = image.size(), n = image[0].size();
        int ocolor = image[sr][sc];
        
        queue<pair<int,int>> q;
        if (ocolor != color)
            q.push({sr,sc});
        
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();
            
            image[x][y] = color;
            for (auto d : delta)
            {
                int nx = x + d.first, ny = y + d.second;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (image[nx][ny] != ocolor) continue;
                q.push({nx,ny});
            }
        }
       
        return image;
    }
};    

