
// Time : O(log(m * n))
// Space : O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1, mid;

        while (left <= right)
        {
            mid = (left + right) / 2;
            int i = mid / n;
            int j = mid % n;

            if (target == matrix[i][j]) return true;
            else if (target < matrix[i][j]) right = mid - 1;
            else if (target > matrix[i][j]) left = mid + 1;
        }
        return false;
    }
};