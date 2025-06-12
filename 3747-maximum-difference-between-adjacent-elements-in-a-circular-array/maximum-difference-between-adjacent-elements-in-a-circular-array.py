class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        # 12.06.25 (potd)
        ans = abs(nums[0] - nums[-1])
        
        for i in range(1,len(nums)):
            ans = max(ans, abs(nums[i] - nums[i-1]))

        return ans