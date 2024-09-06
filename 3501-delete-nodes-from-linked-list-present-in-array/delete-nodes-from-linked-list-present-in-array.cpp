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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // WC 406 14.07.24
        // 06.09.24 (POTD)
        ListNode* h = head, *prev = head;
        set<int> st = {nums.begin(), nums.end()};

        while(st.count(h->val)){
            head = head->next;
            h = head;
            prev = head;
        }

        while(h){
            if(st.count(h->val)){
                prev->next = h->next;
            } else {
                prev = h;
            }
            h = h->next;
        }

        return head;
    }
};