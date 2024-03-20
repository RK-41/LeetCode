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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 20.03.24 POTD
        ListNode *l1=list1, *l2=list2;
        b-=a;

        while(--a>0){
            l1 = l1->next;
        }

        ListNode* r1 = l1->next;
        l1->next = l2;

        while(b-->0){
            r1 = r1->next;
        }

        while(l2->next){
            l2 = l2->next;
        }

        l2->next = r1->next;
        
        return list1;
    }
};