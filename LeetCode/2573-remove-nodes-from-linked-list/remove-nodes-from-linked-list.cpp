/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode *reverse(ListNode*h) {
        ListNode *cur = h, *prev = nullptr;

            while(cur) {
                swap(cur->next, prev);
                swap(prev, cur);
            }
        return prev;
    }
public:
    ListNode *removeNodes(ListNode *h) {
        h = reverse(h);

        for(auto p = h; p && p->next;) {
            if(p->val > p->next->val)
                p->next = p->next->next;
            else
            p = p->next;
        }
        return reverse(h);
    }
};
