
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);  // 2 to the power n

        for (int i = 0; i < (1<<n); i++)
            ans[i] = i ^ (i >> 1);
        return ans;
    }

    unsigned int grayToBinary(unsigned int num)
    {
        unsigned int mask;
        for (mask = num >> 1; mask != 0; mask = mask >> 1)
        {
            num = num ^ mask;
        }
        return num;
    }
};
