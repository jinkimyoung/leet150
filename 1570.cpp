
#include <vector>
#include <unordered_map>
using namespace std;

class SparseVector {
public:
    unordered_map<int, int> mp;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                mp[i] = nums[i];

    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        double product = 0;

        for (auto elem : mp)
        {
            if (vec.mp.find(elem.first) != vec.mp.end())
                product += (elem.second) * vec.mp[elem.first];
        }
        return product;
    }
};

