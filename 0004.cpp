
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n)  return findMedianSortedArrays(nums2, nums1);

        int total = m + n, low = 0, high = m;
        int i, j, left1, left2, right1, right2;
        double result = 0.0;
        while (low <= high)
        {
            i = (low + high) / 2;   // idx in nums1
            j = (m + n + 1) / 2 - i;// idx in nums2
            left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            right1 = (i < m) ? nums1[i] : INT_MAX;
            left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            right2 = (j < n) ? nums2[j] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) result = (max(left1, left2) + min(right1, right2)) / 2.0;
                else result = max(left1, left2);
                break;
            } else if (left1 > right2)
                high = i - 1;
            else
                low = i + 1;     
        }
        return result;
    }
};
