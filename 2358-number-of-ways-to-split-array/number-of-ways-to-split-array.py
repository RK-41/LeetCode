class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        # 03.01.25 POTD
        ans, total, curr, n = 0, sum(nums), 0, len(nums)
        # total and curr are sum

        for i in range(n-1):
            curr += nums[i]
            if curr >= (total - curr):
                ans += 1

        return ans