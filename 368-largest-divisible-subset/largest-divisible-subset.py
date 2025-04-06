class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        # 06.04.25 potd
        ans = []
        nums.sort()
        dp = [1] * len(nums)
        prev = [-1] * len(nums)
        maxi = 0

        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i]%nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    prev[i] = j
            
            if dp[i] > dp[maxi]:
                maxi = i
        
        idx = maxi
        while idx >= 0:
            ans.append(nums[idx])
            idx = prev[idx]
        
        return ans