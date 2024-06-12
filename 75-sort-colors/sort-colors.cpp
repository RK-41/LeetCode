class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 12.06.24 potd
        // Dutch National Flag Problem: RWB
        const char red=0, white=1, blue=2;
        int l=0, m=0, r=nums.size()-1;

        while(m<=r){
            switch(nums[m]){
                case red:
                    swap(nums[l], nums[m]);
                    l++, m++;
                    break;
                case white:
                    m++;
                    break;
                case blue:
                    swap(nums[m], nums[r]);
                    r--;
                    break;
            }
        }
    }
};