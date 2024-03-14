class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 14.03.24 potd
        return atMost(nums, goal) - atMost(nums, goal-1);
    }

    int atMost(vector<int>&nums, int goal){
        int head, tail=0, sum=0, res=0;
        for(head=0; head<nums.size(); head++){
            sum += nums[head];
            while(sum>goal && tail<=head){
                sum -= nums[tail];
                tail++;
            }

            res += head - tail + 1;
        }

        return res;
    }
};