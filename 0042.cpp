
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int maxL = INT_MIN, maxR = INT_MIN, ans = 0;
        int l = 0, r = height.size() - 1;

        while (l < r)
        {
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);
            ans += (maxL - height[l]) + (maxR - height[r]);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};

