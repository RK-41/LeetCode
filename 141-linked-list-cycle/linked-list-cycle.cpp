/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //06.03.24 (POTD)

        // APPROACH: Slow & Fast pointer.
        // Slow ptr moves 1 step at a time and Fast ptr moves 2 steps at a time.
        // If a cycle is present, both the pointers must meet at some point inside the cycle.

        ListNode *slow=head, *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast)
                return true;
        }

        return false;
    }
};