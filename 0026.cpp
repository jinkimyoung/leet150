
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ori = 1, idx = 1;

        while (idx < nums.size())
        {
            if (nums[idx-1] != nums[idx])
                nums[ori++] = nums[idx++];
            else
                idx++;
        }

        return ori;
    }
};

