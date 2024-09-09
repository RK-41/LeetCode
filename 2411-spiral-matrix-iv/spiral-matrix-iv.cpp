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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // 09.09.24 POTD
        vector<vector<int>> ans(m, vector<int>(n,-1));
        ListNode *h = head;
        int left=0, right=n-1, top=0, bottom=m-1;

        while(left<=right && top<=bottom && h){
            // left to right
            for(int j=left; j<=right; j++){
                if(!h)  break;

                ans[top][j] = h->val;
                h = h->next;
            }
            top++;

            // top to bottom
            for(int i=top; i<=bottom; i++){
                if(!h)  break;

                ans[i][right] = h->val;
                h = h->next;
            }
            right--;

            // right to left
            if(top<=bottom){
                for(int j=right; j>=left; j--){
                    if(!h)  break;

                    ans[bottom][j] = h->val;
                    h = h->next;
                }
                bottom--;
            }

            // bottom to top
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    if(!h)  break;

                    ans[i][left] = h->val;
                    h = h->next;
                }
                left++;
            }
        }

        return ans;
    }
};