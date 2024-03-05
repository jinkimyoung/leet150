
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0), *cur = &dummy;
        int n1, n2, carry = 0, s;

        while (l1 || l2)
        {
            n1 = l1 ? l1->val : 0;
            n2 = l2 ? l2->val : 0;
            s = carry + n1 + n2;
            cur->next = new ListNode(s % 10);
            carry = (s >= 10) ? 1 : 0;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            cur = cur->next;
        }

        if (carry)
            cur->next = new ListNode(carry);
        return dummy.next;
    }
};

