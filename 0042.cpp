
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int ans = 0;

        while (l < r)
        {
            if (leftMax <= rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                ans += (leftMax - height[l]);
            }
            else
            {
                r--;
                rightMax = max(rightMax, height[r]);
                ans += (rightMax - height[r]);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1, sum = 0;
        int lMax = 0, rMax = 0;

        while (l < r)
        {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);
            ans = ans + ((lMax - height[l]) + (rMax - height[r]));

            if (height[l] < height[r])
                l++;
            else
                r--;

        }

        return ans;
    }
};
