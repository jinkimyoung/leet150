

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int m = nums.size();
        int sum = 0, total = m * (m+1) / 2;

        for (int num : nums)
            sum += num;
        return (total - sum);
    }
};

