class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // 03.11.23 POTD

        vector<string> ans;
        int j=-1;

        for(int i=1; i<=n; i++){
            ans.push_back("Push");
            j++;

            if(i == target.back())   break;

            if(i != target[j]){
                ans.push_back("Pop");
                j--;
            }
        }

        return ans;
    }
};