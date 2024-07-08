
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int ans = 0;

        for (int price : prices)
        {
            minPrice = min(minPrice, price);
            ans = max(ans, price - minPrice);
        }
        return ans;
    }
};

