class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        # 16.06.25 POTD
        ans = -1
        n = len(nums)
        mn, mx = [nums[0]] * n, [nums[n-1]] * n
        mnv, mxv = nums[0], nums[n-1]
        
        for i in range(n):
            mn[i] = min(mnv, nums[i])
            mx[n-1-i] = max(mxv, nums[n-1-i])
            mnv = mn[i]
            mxv = mx[n-1-i]

        for i in range(n-1):
            ans = max(ans, mx[i+1] - mn[i])
            
        return ans if ans > 0 else -1
