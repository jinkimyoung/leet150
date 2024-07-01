


#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (pos < i)    return false;
            if (i + nums[i] > pos)
                pos = i + nums[i];
        }
        return true;
    }
};


