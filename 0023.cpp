
#include <vector>
#include <queue>

using namespace std;

typedef struct _ListNode {
    int val;
    ListNode *next;
 } ListNode;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while (node)
            {
                pq.push(node->val);
                node = node->next;
            }
        }
        if (pq.empty()) return NULL;
        ListNode *node = new ListNode(pq.top());
        pq.pop();
        ListNode *head = node; 
        while (!pq.empty())
        {
            node->next = new ListNode(pq.top());
            node = node->next;
            pq.pop();
        }
        return head;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int m = lists.size();
        if (!m) return NULL;

        while (m > 1) 
        {
            for (int i = 0; i < (m/2); i++)
                lists[i] = mergeTwolists(lists[i], lists[m - i - 1]);
            m = (m + 1) / 2;
        }
        return lists[0];        
    }

    ListNode* mergeTwolists(ListNode *h1, ListNode *h2)
    {
        if (!h1 && !h2) return NULL;
        else if (!h1)   return h2;
        else if (!h2)   return h1;

        ListNode dummy(0), *cur = &dummy;
        while (h1 && h2)
        {
            if (h1->val < h2->val)
            {
                cur->next = h1;
                h1 = h1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = h2;
                h2 = h2->next;
                cur = cur->next;
            }
        }
        if (h1) cur->next = h1;
        else if (h2) cur->next = h2;
        return dummy.next;
    }
};