class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 23.06.24 potd
        deque<int> inc, dec;
        int mxLen=0, left=0;

        for(int right=0; right<nums.size(); right++){
            while(!inc.empty() && nums[right] < inc.back()){
                inc.pop_back();
            }
            inc.push_back(nums[right]);

            while(!dec.empty() && nums[right] > dec.back()){
                dec.pop_back();
            }
            dec.push_back(nums[right]);

            while(dec.front() - inc.front() > limit){
                if(nums[left] == dec.front()){
                    dec.pop_front();
                }
                if(nums[left] == inc.front()){
                    inc.pop_front();
                }
                ++left;
            }

            mxLen = max(mxLen, right-left+1);
        }

        return mxLen;
    }
};