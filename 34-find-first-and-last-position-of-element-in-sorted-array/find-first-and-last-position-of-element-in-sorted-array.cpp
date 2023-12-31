class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // 22.09.23
        // 09.10.23 POTD (Resubmission)
        
        int first=-1, last=-1, n=nums.size();

        // Finding first position
        int lo=0, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid] == target){
                if(mid==0 || nums[mid-1]<target){
                    first=mid;
                    break;
                }
                else{
                    hi=mid-1;
                }
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }

        // Finding last position
        lo=0, hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(nums[mid] == target){
                if(mid==n-1 || nums[mid+1]>target){
                    last = mid;
                    break;
                }
                else{
                    lo=mid+1;
                }
            }
            else if(nums[mid]>target){
                hi=mid-1;
            }
            else
                lo=mid+1;
        }

        return {first, last};
    }
};