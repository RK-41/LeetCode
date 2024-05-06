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
    ListNode* removeNodes(ListNode* head) {
        // 06.05.24 POTD
        ListNode* ans=new ListNode(0), *h=head;
        stack<int> stk, res;

        while(h){
            stk.push(h->val);
            h = h->next;
        }

        res.push(stk.top());
        stk.pop();
        
        while(stk.size()){
            if(stk.top() >= res.top())
                res.push(stk.top());

            stk.pop();
        }

        ListNode* a = ans;

        while(res.size()){
            a->next = new ListNode(res.top());
            a = a->next;
            
            res.pop();
        }

        return ans->next;
    }
};