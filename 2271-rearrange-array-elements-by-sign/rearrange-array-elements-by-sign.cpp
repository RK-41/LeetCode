class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // 14.02.24 POTD
        vector<int> pos, neg;
        int n=nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]<0)
                neg.push_back(i);
            else 
                pos.push_back(i);
        }

        // APPROACH I: Using another vector
        vector<int> ans;
        for(int i=0; i<n/2; i++){
            ans.push_back(nums[pos[i]]);
            ans.push_back(nums[neg[i]]);
        }

        return ans;

        // APPROACH II: Operating on the given vector (NOT PERFECT)
        // int i=0, j=0, k=0;
        // while(i<n && j<pos.size() && k<neg.size()){
        //     if(i%2==0 && nums[i]<0){
        //         int t=nums[i];
        //         if(nums[neg[k]]>=0){
        //             nums[i]=nums[neg[k]];
        //             nums[neg[k]]=t;
        //             k++;
        //         } else {
        //             nums[i]=nums[pos[j]];
        //             nums[pos[j]]=t;
        //             j++;
        //         }
        //     }

        //     if(i%2==1 && nums[i]>=0){
        //         int t=nums[i];
        //         if(nums[pos[k]]<0){
        //             nums[i]=nums[pos[j]];
        //             nums[pos[j]]=t;
        //             j++;
        //         } else {
        //             nums[i]=nums[neg[k]];
        //             nums[neg[k]]=t;
        //             k++;
        //         }
        //     }
            
        //     i++;

        // }

        // return nums;

    }
};