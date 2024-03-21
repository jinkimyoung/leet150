
#include <stdio.h>
#include <stdlib.h>

void sum_f(int *c, int *a, int *b)
{
    *c = *a + *b;
}

int main(void)
{
    int n1 = 10, n2 = 20;
    int sum1;

    sum_f(&sum1, &n1, &n2);
    printf("%d\n", sum1);
    
    return 1;
}


class Solution {
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, root->val, ans);
        return ans;
    }

    void dfs(TreeNode *root, int maxSoFar, int &ans)
    {
        if (!root)  return;
        if (root->val >= maxSoFar)  ans++;

        dfs(root->left, max(root->val, maxSoFar), ans);
        dfs(root->right, max(root->val, maxSoFar), ans);        
    }
};