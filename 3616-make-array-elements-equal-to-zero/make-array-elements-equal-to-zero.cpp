class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        // 28.10.25 (POTD)
        int ans=0, sum=0, n=nums.size();
        vector<int> zPos, cumSum;

        for(int i=0; i<n; i++){
            sum += nums[i];
            cumSum.push_back(sum);

            if(nums[i] == 0)
                zPos.push_back(i);
        }

        for(auto p: zPos){
            int left = cumSum[p];
            int right = cumSum.back() - cumSum[p];

            if(abs(right - left) <= 1){
                if(right > left || left > right)
                    ans++;
                else if(right == left)
                    ans += 2;
            }

        }

        return ans;
    }
};