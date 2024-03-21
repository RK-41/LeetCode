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
    ListNode* reverseList(ListNode* head) {
        // 21.03.24 POTD
        ListNode* h=head, *prev=NULL;

        while(h){
            ListNode *nxt = h->next;
            h->next = prev;
            prev = h;
            h = nxt;
        }

        return prev;
    }
};