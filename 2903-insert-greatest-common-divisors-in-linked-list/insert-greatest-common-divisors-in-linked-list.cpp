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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // 10.09.24 POtd
        if(!head->next)    return head;

        ListNode *h=head;

        while(h->next){
            int g = gcd(h->val, h->next->val);
            ListNode *nd = new ListNode(g);
            nd->next = h->next;
            h->next = nd;
            h = nd->next;
        }

        return head;
    }

    int gcd(int a, int b){
       while(b != 0){
        int t = b;
        b = a%b;
        a = t;
       }

       return a;
    }
};