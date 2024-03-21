
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums, 0, cur, ans);
        return ans;
    }

    // [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
    void dfs(vector<int>& nums, int idx, vector<int> &cur, vector<vector<int>> &ans)
    {
        for (int n : cur)
            cout << n << " ";
        cout << endl;

        ans.push_back(cur);
        for (int i = idx; i < nums.size(); i++)
        {
            cur.push_back(nums[i]);
            dfs(nums, i+1, cur, ans);
            cur.pop_back();
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {1,2,3};

    s.subsets(nums);
    
    return 0;
}


struct pci_driver {
	.name = "pcifdafd",
	.id_table = pci_ids;
	.probe = my function
} ;

