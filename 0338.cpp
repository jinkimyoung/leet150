
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);

        for (int i = 1; i <= n; i++)
            dp[i] = dp[i >> 0x1] + (i & 0x1);

        return dp;
    }
};