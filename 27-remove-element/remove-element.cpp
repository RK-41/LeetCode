class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 20.04.26
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1 && nums[0] == val)  return 0;

        int i=0, j=0;

        while(i<n && j<n){
            while(i<n && nums[i] != val){
                i++;
            }
            j = i+1;
            while(j<n && nums[j] == val){
                j++;
            }
            if(i<n && j<n && i<j){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }

        return i;
    }
};