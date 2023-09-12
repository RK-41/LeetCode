class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        if(nums.size()==1)  return 1;
        if(nums.size()==2)  return 2;

        int mxi=0, mni=0;

        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[mni])
                mni=i;
            
            if(nums[i]>nums[mxi])
                mxi=i;
        }

        int n = nums.size();
        int del1 = max(mxi+1, mni+1);   // for front deletion only
        int del2 = max(n-mxi, n-mni);   // for back deletion only
        int del3 = min(mxi+1, mni+1) + min(n-mxi, n-mni);   // for both-side deletion

        return min(min(del1, del2), del3);
    }
};