
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0, m, n);
            dfs(board, i, n-1, m, n);            
        }
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j, m, n);
            dfs(board, m-1, j, m, n);            
        }
    
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

        for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (board[i][j] == 'E')
                        board[i][j] = 'O';                    
    }

    void dfs(vector<vector<char>> &b, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return ;
        if (b[i][j] != 'O') return ;

        b[i][j] = 'E';
        dfs(b, i+1, j, m, n);
        dfs(b, i-1, j, m, n);
        dfs(b, i, j+1, m, n);
        dfs(b, i, j-1, m, n);                        
    }
};