#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int rows = forest.size();, cols = forest[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(forest[i][j] > 1)
                    pq.push({forest[i][j], {i, j}});

        int ans = 0, start_i = 0, start_j = 0;

        // on reaching target treee start from that to next bigger tree
        while(!pq.empty()){
            int target_i = pq.top().second.first, target_j = pq.top().second.second;
            pq.pop();

            int steps = bfs(forest, start_i, start_j, target_i, target_j);
            if(steps == -1) return -1;

            ans += steps;
            start_i = target_i;
            start_j = target_j;
        }
        return ans;
    }

    int bfs(vector<vector<int>>& forest, int start_i, int start_j, int end_i, int end_j){
        int rows = forest.size(), cols = forest[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> que;

        vis[start_i][start_j] = 1;
        que.push({{start_i, start_j}, 0});

        while(!que.empty()){
            int r = que.front().first.first, c = que.front().first.second, steps = que.front().second;
            que.pop();

            if(r == end_i && c == end_j) return steps;

            int row_del [] = {-1, 0, 1, 0}, col_del [] =  {0, 1, 0, -1};
            for(int k = 0; k < 4; k++){
                int nrow = r + row_del[k], ncol = c + col_del[k];

                if(nrow < rows && nrow >= 0 && ncol < cols && ncol >= 0 && vis[nrow][ncol] == 0 && forest[nrow][ncol] != 0){
                    vis[nrow][ncol] = 1;
                    que.push({{nrow, ncol}, steps+1});   
                }
            }
        }
        return -1;
    }    
};