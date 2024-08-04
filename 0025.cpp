
 struct ListNode {
  int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head), *groupPrev = &dummy;
        
        while (true)
        {
            ListNode *kth = getKth(groupPrev, k);
            if (!kth) break;
            
            ListNode *groupNext = kth->next;            
            ListNode *prev = kth->next, *cur = groupPrev->next, *next;
            while (cur != groupNext)
            {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            // update prev's link
            next = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = next;
        }
        return dummy.next;
    }
    
    ListNode* getKth(ListNode *node, int k)
    {
        while (node && k > 0)
        {
            node = node->next;
            k--;
        }
        return node;
    }
};

