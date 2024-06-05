

#include <iostream>
#include <bitset>
using namespace std;
 
// Find the total number of bits needed to be flipped to convert `x` to `y`
int findBits(int x, int y)
{
    // take XOR of `x` and `y` and store in `n`
    int n = x ^ y;
 
    // Using Brian Kernighan’s algorithm to count set bits
 
    // `count` stores the total bits set in `n`
    int count = 0;
 
    while (n)
    {
        n = n & (n - 1);    // clear the least significant bit set
        count++;
    }
 
    return count;
}
 
int main()
{
    int x = 65;
    int y = 80;
 
    std::cout << x << " in binary is " << bitset<8>(x) << endl;
    std::cout << y << " in binary is " << bitset<8>(y) << endl;
 
    std::cout << "\nThe total number of bits to be flipped is " << findBits(x, y);
 
    return 0;
}

// Compute a power of two less than or equal to `n`
unsigned findPreviousPowerOf2(unsigned n)
{
    // do till only one bit is left
    while (n & n - 1) {
        n = n & n - 1;        // unset rightmost bit
    }
 
    // `n` is now a power of two (less than or equal to `n`)
    return n;
}



// Using Brian Kernighan’s algorithm
int countSetBits(int n)
{
    int count = 0;

    while (n)
    {
        // clear the least significant bit set
        n = n & (n - 1);    
        count++;
    }
     return count;
}

// Function to find XOR of two numbers without using XOR operator
int findBits(int x, int y) {
    return (x | y) - (x & y);
}

// Returns true if adjacent bits are set in a binary representation of `n`
bool checkAdjacentBits(int n) {
    return n & (n << 1);
}
 
// Returns true if `n` is a power of four
bool checkPowerOf4(unsigned n)
{
    // return true if `n` is a power of 2, and
    // the remainder is 1 when divided by 3
    return !(n & (n - 1))&& (n % 3 == 1);
}

// Returns true if `n` is a power of 8
bool checkPowerOf8(unsigned n)
{
    // return true if `n` is a power of 2, and its only
    // set bit is present at (0, 3, 6, … ) position
    return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}
// Use mask 0xAAAAAAAA to check for power of 4
// Use mask 0xEEEEEEEE to check for power of 16

// Function to swap b–bits starting from position `p` and `q` in an integer `n`
int swap(int n, int p, int q, int b)
{
    // take XOR of bits to be swapped
    int x = ((n >> p) ^ (n >> q));
 
    // only consider the last b–bits of `x`
    x = x & ((1 << b) - 1);
 
    // replace the bits to be swapped with the XORed bits
    // and take its XOR with `n`
    return n ^ ((x << p) | (x << q));
}

 
// Function to perform left circular shift or right circular shift
// on integer `n` by `k` positions based on flag `isLeftShift`
int circularShift(unsigned n, int k, bool isLeftShift)
{
    // left shift by `k`
    if (isLeftShift) {
        return (n << k) | (n >> (32 - k));
    }
 
    // right shift by `k`
    return (n >> k) | (n << (32 - k));
}

// two pointer
class Solution {
public:
    string longestPalindrome(string s) {
        int m = s.length();
        int maxLen = 0, offset = 0;
        
        for (int i = 0; i < m; i++)
        {
            palindrome(s, i, i, m, maxLen, offset);
            palindrome(s, i, i+1, m, maxLen, offset);                
        }
        return s.substr(offset, maxLen);
    }
    
    
    void palindrome(string &s, int l, int r, int m, int &maxLen, int &offset)
    {
        
        int len = (l == r) ? -1 : 0;
        
        while (l >= 0 && r < m && s[l] == s[r])
        {
            len += 2;
            if (len > maxLen)
            {
                maxLen = len;
                offset = l;                
            }
            l--;
            r++;
        }
    }
};


#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs)
        {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].push_back(s);
        }
        
        for (auto e : mp)
            ans.push_back(e.second);
        
        return ans;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size() - 1, lMax = INT_MIN, rMax = INT_MIN;
        
        while (l < r)
        {
            lMax = max(height[l], lMax);
            rMax = max(height[r], rMax);
            if (lMax < rMax)
            {
                ans += (lMax - height[l]);
                l++;
            }
            else
            {
                ans += (rMax - height[r]);
                r--;
            }
        }
        return ans;
    }
};


#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size()-1, t = 0, b = matrix.size()-1;
        vector<int> ans;

        while (l <= r && t <= b)
        {
            for (int i = l; i <= r; i++)
                ans.push_back(matrix[t][i]);
            t++;    

            for (int j = t; j <= b; j++)
                ans.push_back(matrix[j][r]);
            r--;    

            if (t <= b)
            {            
                for (int i = r; i >= l; i--)
                    ans.push_back(matrix[b][i]);
                b--;
            }
            if (l <= r)
            {
                for (int j = b; j >= t; j--)
                    ans.push_back(matrix[j][l]);
                l++;    
            }
        }
        return ans;
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 



class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                return true;
        }
        
        return false;
    }
};

// Not to use reverse, use STK.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode *cur = NULL, *next = NULL;
        int carry = 0, val = 0;
        while (!s1.empty() || !s2.empty())
        {
            val = carry + (!s1.empty() ? s1.top() : 0) + (!s2.empty() ? s2.top() : 0);
            carry = (val >= 10) ? 1 : 0;
            cur = new ListNode(val % 10);
            cur->next = next;
            next = cur;
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }
        
        if (carry)
        {
            cur = new ListNode(1);
            cur->next = next;        
        }
        return cur;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = {}, *cur = &dummy;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1)  cur->next = list1;
        else if (list2) cur->next = list2;
       
        return dummy.next;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        while (n > 1)
        {
            for (int i = 0; i < (n/2); i++)
                lists[i] = mergeTwoList(lists[i], lists[n - 1 - i]);
            n = (n + 1) / 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoList(ListNode *h1, ListNode *h2)
    {
        ListNode dummy = {0}, *cur = &dummy;
        while (h1 && h2)
        {
            if (h1->val < h2->val)
            {
                cur->next = h1;
                h1 = h1->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
            }
            cur = cur->next;
        }
        if (h1) cur->next = h1;
        else if (h2)    cur->next = h2;
        return dummy.next;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *n1 = headA, *n2 = headB;
        while (n1 != n2)
        {
            n1 = n1 ? n1->next : headB;
            n2 = n2 ? n2->next : headA;
        }
        return n1;
    }
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *cur = head;
        while (cur)
        {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        while (cur)
        {
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];            
            cur = cur->next;
        }
        return mp[head];
    }
};


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs(TreeNode *node, long minVal, long maxVal)
    {
        if (!node)  return true;
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        
        return dfs(node->left, minVal, node->val) && dfs(node->right, node->val, maxVal);
    }
};

#include <stack>


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode *node = root;
        
        while (node || !stk.empty())
        {
            while (node)
            {
                stk.push(node);
                node = node->left;
            }
            
            node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            
            node = node->right;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }

    void helper(TreeNode *node, vector<int> &ans)
    {
        if (!node)  return ;

        helper(node->left, ans);
        ans.push_back(node->val);
        helper(node->right, ans);
    }
};

#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>    q;

        if (!root)  return ans;
        
        q.push(root);
        while (!q.empty())
        {
            vector<int> list;
            int num = q.size();
            for (int i = 0; i < num; i++)
            {
                TreeNode *n = q.front();
                q.pop();
                list.push_back(n->val);
                
                if (n->left)    q.push(n->left);
                if (n->right)   q.push(n->right);
            }
            ans.push_back(list);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)  return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool bLeft = true;
        
        while (!q.empty())
        {
            vector<int> list;
            int len = q.size();

            for (int i = 0; i < len; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                list.push_back(cur->val);

                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (!bLeft)
                reverse(list.begin(), list.end());
            bLeft = (bLeft == false) ? true : false;
            ans.push_back(list);
        }
        return ans;
    }
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty())
        {
            Node *prev = NULL, *curr = NULL;
            int nElement = q.size();
            for (int i = 0; i < nElement; i++)
            {
                curr = q.front();
                q.pop();

                curr->next = NULL;
                if (curr->left) q.push(curr->left);
                if (curr->right)    q.push(curr->right);
                
                if (prev)   prev->next = curr;
                prev = curr;
            }
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root)  return NULL;
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n_element = q.size();
            Node *prev = NULL, *cur = NULL;
            for (int i = 0; i < n_element; i++)
            {
                cur = q.front();
                q.pop();
                if (prev)
                    prev->next = cur;
                cur->next = NULL;
                
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
                prev = cur;
            }
        }
        return root;
    }
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val < p->val && cur->val < q->val)
                cur = cur->right;
            else if (cur->val > p->val && cur->val > q->val)
                cur = cur->left;
            else
                return cur;
        }
        return NULL;
    }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (!root)  return NULL;
        if (root->val == p->val || root->val == q->val) return root;

        TreeNode *left  = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right)  return root;
        
        if (left)   return left;
        if (right)  return right;
        
        return NULL;
    }
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i > j) return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) 
            if (preorder[index] == inorder[i]) 
                split = i;

        index++;
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        return root;
    }
};


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    ans++;
                } 
            }
        }
        return ans;
    }
    
    bool dfs(vector<vector<char>> &g, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (g[i][j] == '0')   return false;
        g[i][j] = '0';
        
        dfs(g, i+1, j, m, n);
        dfs(g, i-1, j, m, n);
        dfs(g, i, j+1, m, n);
        dfs(g, i, j-1, m, n);        
        return true;
    }
};

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        
        if (!node)  return NULL;
        q.push(node);
        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            
            if (mp.find(n) == mp.end())
                mp[n] = new Node(n->val);
            for (int i = 0; i < n->neighbors.size(); i++)
            {
                Node *c = n->neighbors[i];
                if (mp.find(c) == mp.end())
                {
                    mp[c] = new Node(c->val);                    
                    q.push(c);
                }
                mp[n]->neighbors.push_back(mp[c]);
            }
        }
            
        return mp[node];
    }
};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        unordered_map<char, string> letters = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string phoneDigits;

        if (digits.length() == 0) {
            return combinations;
        }
        phoneDigits = digits;
        backtrack(combinations, letters, phoneDigits, 0, "");
        
        return combinations;
    }

    void backtrack(vector<string> &combinations, unordered_map<char, string> &letters, string &phoneDigits, int index, string path ) {
        if (path.length() == phoneDigits.length()) {
            combinations.push_back(path);
            return;
        }
        string possibleLetters = letters[phoneDigits[index]];
        for (char letter : possibleLetters) {
            path.push_back(letter);
            backtrack(combinations, letters, phoneDigits, index + 1, path);
            path.pop_back();
        }
    }    
};


class TrieNode {
public:
    TrieNode    *child[26];
    bool    isWord;

    TrieNode() { isWord = false; for (int i = 0; i < 26; i++)   child[i] = NULL;}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode root, *cur;

        for (int i = 0; i < 26; i++)
            root.child[i] = NULL;
        root.isWord = false; 

        for (string w : words)
        {
            cur = &root;
            for (char c : w)
            {
                if (!cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }
            cur->isWord = true;
        }

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(i, j, m, n, board, "", &root, ans);
        return ans;
    }

     void dfs(int i, int j, int m, int n, vector<vector<char>> &b, string s, TrieNode *node, vector<string> &ans)
     {
        if (i < 0 || i >= m || j < 0 || j >= n || !node)    return ;
        char c = b[i][j];
        if (c == '#')   return ;
        if (!node->child[c-'a'])    return ;

        s += c;
        node = node->child[c-'a'];
        if (node->isWord)
        {
            ans.push_back(s);
            node->isWord = false;
        }
        b[i][j] = '#';
        dfs(i+1, j, m, n, b, s, node, ans);
        dfs(i-1, j, m, n, b, s, node, ans);        
        dfs(i, j+1, m, n, b, s, node, ans);
        dfs(i, j-1, m, n, b, s, node, ans);        
        b[i][j] = c;
     }
};


class Solution {
public:
    bool solvetab(string s, string p)
    {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[0][0]=true;
        for(int j=1;j<=p.length();j++)
        {
            bool flag= true;
            for(int k =1;k<=j;k++)
            {
                if(p[k-1]!='*')
                {
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i = 1;i <= s.length(); i++)
        {
            for(int j = 1;j <= p.length(); j++)
            {
                if(p[j-1] == '?' || p[j-1] == s[i-1])
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1] =='*')
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else
                    dp[i][j]=false;
            }
        }
        return dp[s.length()][p.length()];
    }

    bool isMatch(string s, string p)
    {
        return solvetab(s,p);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int oIdx = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (oIdx > 0 && nums[oIdx-1] == nums[i])
                continue;
            nums[oIdx++] = nums[i];
        }
        return oIdx;
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, idx = (m + n) - 1;

        while (idx >= 0)
        {
            if (i < 0)
                nums1[idx--] = nums2[j--];
            else if (j < 0)                
                nums1[idx--] = nums1[i--];
            else
            {
                if (nums1[i] < nums2[j])
                    nums1[idx--] = nums2[j--];
                else
                    nums1[idx--] = nums1[i--];                
            }
        }
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (int num : nums)
            mp[num]++;

        int idx = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < mp[i]; j++)
                nums[idx++] = i;
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
  

  
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, m = 0, r = nums.size() - 1;

        while (l < r)
        {
            m = (l + r) / 2;
            if (nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        } 
        return nums[l];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int m = (l + r)/2;
            if(nums[m] < nums[r])
                r = m;
            else if(nums[m] > nums[r]) 
                l = m+1;
            else
                r--;
        }
        return nums[l];
    }
};