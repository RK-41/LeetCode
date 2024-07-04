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
public:
    ListNode* mergeNodes(ListNode* head) {
        // 04.07.24 POTD
        ListNode* ans = new ListNode(0);
        ListNode *h = head->next, *a = ans;

        while(h){
            if(h->val == 0 && h->next){
                a->next = new ListNode(0);
                a = a->next;
            } else {
                a->val += h->val;
            }

            h = h->next;
        }

        return ans;
    }
};