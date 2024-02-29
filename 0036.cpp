
// hashset

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};
        int idx, area;

        for (int r = 0; r < cnt; r++)
        {
            for (int c = 0; c < cnt; c++)
            {
                if (board[r][c] == '.') continue;
                idx = board[r][c] - '0' - 1;
                area = (r/3)*3 + (c/3);

                if (row[r][idx] || col[c][idx] || sub[area][idx])   return false;

                row[r][idx] = col[c][idx] = sub[area][idx] = true;
            }    
        }
        return true;
    }
};