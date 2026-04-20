class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // 20.04.26
        int ans=0, n=colors.size();
        
        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                if(colors[i] != colors[j]){
                    ans = max(ans, j-i);
                    break;
                }
            }
        }

        return ans;
    }
};