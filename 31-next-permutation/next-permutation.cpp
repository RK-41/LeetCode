class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 31.05.24
        int n=nums.size();
        int bp=-1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }

        if(bp == -1){
            reverse(nums);
        } else {
            for(int i=n-1; i>=0; i--){
                if(nums[i] > nums[bp]){
                    swap(nums[i], nums[bp]);
                    break;
                }
            }

            reverse(nums, bp+1);
        }
    }

    void reverse(vector<int>& v, int start=0){
        int n=v.size();

        for(int i=start; i<(n+start)/2; i++){
            swap(v[i], v[n-1-i+start]);
        }
    }
};