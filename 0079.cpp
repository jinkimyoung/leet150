
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0])
                    if (bts(board, i, j, m, n, 0, word))
                        return true;
        return false;
    }
    
    bool bts(vector<vector<char>> &b, int i, int j, int m, int n, int idx, string &s)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (b[i][j] != s[idx]) return false;
        if (s.length()-1 == idx) return true;
        
        char c = b[i][j];
        b[i][j] = '#';
        if (bts(b, i+1, j, m, n, idx+1, s) || bts(b, i, j+1, m, n, idx+1, s) ||
            bts(b, i-1, j, m, n, idx+1, s) || bts(b, i, j-1, m, n, idx+1, s))
            return true;
        b[i][j] = c;
        return false;
    }
};

