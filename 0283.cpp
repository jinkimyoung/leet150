

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nzero = 0;

        for (int src = 0, dst = 0; dst < nums.size(); dst++)
        {
            if (nums[dst] != 0)
                nums[src++] = nums[dst];
            else
                nzero++;
        }        

        for (int i = nums.size() - 1; i >= 0 && nzero > 0; i--, nzero--)
            nums[i] = 0;
    }
};

