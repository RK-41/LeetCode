class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // 28.03.24 potd
        int ans=0, n=nums.size();
        unordered_map<int,queue<int>> fo;
        // fo: first occurence

        for(int l=0, r=0; r<n; r++){
            fo[nums[r]].push(r);

            // Size of queue is frequency of element
            // If frequency if k+1, remove one


            if(fo[nums[r]].size() == k+1){
                // Here, l (left) is starting point of the window
                // If first occurence is inside window, update l (left)
                if(fo[nums[r]].front() >= l){
                    l = fo[nums[r]].front()+1;
                }

                fo[nums[r]].pop();
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};