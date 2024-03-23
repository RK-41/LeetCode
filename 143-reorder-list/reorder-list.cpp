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
    void reorderList(ListNode* head) {
        // 23.03.24 potd
        if(!head)
            return;

        ListNode *hd=head, *half=head, *prev=NULL;
        
        // Finding the middle node
        while(hd->next && hd->next->next){
            hd = hd->next->next;
            half = half->next;
        }

        // Adding one bit in case of even-length list
        if(hd->next)
            half = half->next;

        // Reversing the second half
        while(half){
            hd = half->next;
            half->next = prev;
            prev = half;
            half = hd;
        }
        half = prev;
        
        // Merging both the halves
        while(head && half){
            hd = head->next;
            prev = half->next;
            head->next = half;
            half->next = hd;
            head = hd;
            half = prev;
        }

        // Base case: closing for even-length list
        if(head && head->next)
            head->next->next = NULL;
    }
};