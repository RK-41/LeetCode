class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 07.04.25 POTD
        tot = sum(nums)
        if tot%2 == 1:  return False

        hlf = tot // 2
        dp = [False] * (hlf + 1)
        dp[0] = True

        for x in nums:
            for currSm in range(hlf, x-1, -1):
                dp[currSm] = dp[currSm] or dp[currSm - x]
        
        return dp[hlf]
