
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 0, mid = 0;
        int ans = 0;

        for (int pile : piles)
            high = max(high, pile);
        ans = high;
        while (low <= high)
        {
            mid = (low + high) / 2;
            double hours = 0;
            for (int pile : piles)
                hours += ceil((double)pile / mid);  // Double이 중요함

            if (hours <= h)
            {
                ans = min(ans, mid);
                high = mid - 1;
            } 
            else
                low = mid + 1;
        }
        return ans;
    }
};