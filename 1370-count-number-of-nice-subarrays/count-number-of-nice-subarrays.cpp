class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 22.06.24 POTD
        int ans=0, n=nums.size();
        vector<int> oddPos;

        for(int i=0; i<n; i++){
            if(nums[i]%2 == 1)
                oddPos.push_back(i);
        }

        int os = oddPos.size();

        if(os < k){
            return 0;
        }

        int lastOdd = 0;
        for(int i=k-1; i<os; i++){
            int left=1, right=1;

            if(oddPos[lastOdd] > 0){
                left = oddPos[lastOdd];
                if(lastOdd > 0)
                    left -= oddPos[lastOdd-1];
                else
                    left++;
            }
            
            if(i < os-1){
                right = oddPos[i+1] - oddPos[i];
            } else {
                right = n - oddPos[i];
            }

            ans += left*right;
            lastOdd++;
        }

        return ans;
    }
};