class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        # 03.02.25 POTD
        ans, i, j, n = 0, 0, 1, len(nums)

        while j<n:
            if nums[j-1] >= nums[j]:
                ans = max(ans, j-i)
                i = j
            j += 1
        
        ans = max(ans, j-i)

        i, j = 0, 1
        while j<n:
            if nums[j-1] <= nums[j]:
                ans = max(ans, j-i)
                i = j
            j += 1

        ans = max(ans, j-i)
        return ans
