
// Time : O(N), Space : O(1)
struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr, *next;

        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

