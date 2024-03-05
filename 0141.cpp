
struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)  return false;
        
        ListNode *cur1 = head->next, *cur2 = head;

        while (cur1 != cur2)
        {
            if (cur1 == nullptr || cur1->next == nullptr)
                return false;

            cur1 = cur1->next->next;
            cur2 = cur2->next;
        }
        return true;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)  return false;

        ListNode *slow = head, *fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};