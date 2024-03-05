

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = { 0 }, *cur = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                cur = cur->next;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = cur->next;
                list2 = list2->next;
            }
        }
        if (list1 != nullptr)   cur->next = list1;
        else if (list2 != nullptr)   cur->next = list2;        

        return dummy.next;
    }
};

