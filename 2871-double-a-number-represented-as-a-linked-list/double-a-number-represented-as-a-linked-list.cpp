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
    ListNode* doubleIt(ListNode* head) {
        // 07.05.24 POTD
        int carry = 0;
        helper(head, carry);

        while(carry){
            ListNode* nd = new ListNode(carry%10);
            nd->next = head;
            head = nd;
            carry /= 10;
        }

        return head;
    }

    void helper(ListNode* curr, int &carry){
        if(!curr)   return;

        helper(curr->next, carry);

        carry += 2*curr->val;
        curr->val = carry%10;
        carry /= 10;
    }
};