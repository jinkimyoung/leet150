
struct ListNode {
    int val;
    ListNode *next;
};


class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)    return ;
        ListNode dummy = {0}, *node1, *node2, *tmp1, *tmp2;

        node1 = head;
        node2 = reverse(getMiddle(head));
        while (node1 != nullptr && node2 != nullptr)
        {
            tmp1 = node1->next;
            tmp2 = node2->next;

            node1->next = node2;
            node2->next = tmp1;

            node1 = tmp1;
            node2 = tmp2;
        }
        // Set NULL at the end of node.
        if (node1)  node1->next = nullptr;
        if (node2)  node2->next = nullptr;

        return ;        
    }

    ListNode* getMiddle(ListNode *head)
    {
        ListNode *cur1 = head, *cur2 = head;

        while (cur2 != nullptr && cur2->next != nullptr)
        {
            cur1 = cur1->next;
            cur2 = cur2->next->next;
        }
        return cur1;
    }

    ListNode* reverse(ListNode *head)
    {
        ListNode *cur = head, *prev = NULL, *next;
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