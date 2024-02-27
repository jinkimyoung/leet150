
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, area;
        int l = 0, r = height.size() - 1;

        while (l < r)
        {
            area = (r - l) * min(height[l], height[r]);
            ans = max(ans, area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

	    return ans;
    }
};