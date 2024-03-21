
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (word[0] == board[i][j])
                    if (dfs(i, j, m, n, board, 0, word))
                        return true;
        return false;
    }

    bool dfs(int i, int j, int m, int n, vector<vector<char>> &b, int idx, string s)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (s[idx] != b[i][j])    return false; 
        if (idx == s.length() - 1)  return true; // ['a']

        char c = b[i][j];
        b[i][j] = '#';
        if (dfs(i+1, j, m, n, b, idx+1, s) || dfs(i, j+1, m, n, b, idx+1, s) ||
            dfs(i-1, j, m, n, b, idx+1, s) || dfs(i, j-1, m, n, b, idx+1, s))
            return true;
        b[i][j] = c;    
        return false;    
    }
};

