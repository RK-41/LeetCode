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
    bool isPalindrome(ListNode* head) {
        // 22.03.24 (potd)
        return reverseCheck(head, head);
    }

    bool reverseCheck(ListNode* hd, ListNode* &nd){
        if(hd){
            bool res = reverseCheck(hd->next, nd);
            if(hd->val == nd->val){
                nd = nd->next;
                return res && true;
            } else {
                nd = nd->next;
                return false;
            }
        } else {
            return true;
        }
    }
};