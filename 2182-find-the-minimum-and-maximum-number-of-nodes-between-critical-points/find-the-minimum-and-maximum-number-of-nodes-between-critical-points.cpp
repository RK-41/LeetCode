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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // 05.07.24 POTD
        vector<int> ans(2,INT_MAX), cps;
        ListNode *prev = head, *h=head->next;
        int n=1;

        while(h->next){
            if(prev->val > h->val && h->val < h->next->val)
                cps.push_back(n);
            else if(prev->val < h->val && h->val > h->next->val)
                cps.push_back(n);

            n++;
            prev = h;
            h=h->next;
        }

        if(cps.size() < 2){
            return {-1,-1};
        }

        for(int i=1; i<cps.size(); i++){
            ans[0] = min(ans[0], cps[i] - cps[i-1]);
        }
        ans[1] = cps.back()-cps[0];

        return ans;
    }
};