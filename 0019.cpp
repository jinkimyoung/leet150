

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode *l = &dummy, *r = head;

        for (int i = 0; i < n; i++)
            r = r->next;
        while (r)
        {
            r = r->next;
            l = l->next;
        }
        l->next = l->next->next;

        return dummy.next;
    }
};