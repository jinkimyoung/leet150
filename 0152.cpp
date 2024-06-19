
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double minP, maxP;
        int abs;

        minP = maxP = abs = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(minP, maxP);
            minP = min((double)nums[i], (minP * nums[i]));
            maxP = max((double)nums[i], (maxP * nums[i]));
            abs = max(abs, (int)maxP);            
        }
        return abs;
    }
};
