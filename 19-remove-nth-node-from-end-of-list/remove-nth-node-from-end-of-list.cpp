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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 03.03.24 POTD
        int total=0;
        ListNode* h=head;
        while(h){
            total++;
            h=h->next;
        }

        if(total==n)
            return head->next;

        int m=total-n;
        h=head;
        while(--m > 0){
            h=h->next;
        }

        h->next = h->next->next;

        return head;
    }
};