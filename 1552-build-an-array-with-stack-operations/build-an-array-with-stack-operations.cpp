class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // 03.11.23 POTD

        vector<string> ans;
        // vector<int> stk;
        int j=-1;

        // for(int i=1; i<=n; i++){
        //     stk.push_back(i);
        //     ans.push_back("Push");

        //     if(stk == target)   break;

        //     if(stk[j] != target[j]){
        //         stk.pop_back();
        //         ans.push_back("Pop");
        //         j--;
        //     }

        //     j++;
        // }

        for(int i=1; i<=n; i++){
            // stk.push_back(i);
            ans.push_back("Push");
            j++;

            if(i == target.back())   break;

            if(i != target[j]){
                // stk.pop_back();
                ans.push_back("Pop");
                j--;
            }
        }

        return ans;
    }
};