class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        # 18.03.25 potd
        n, maxLen, left, usedBits = len(nums), 1, 0, 0

        for right in range(n):
            while usedBits & nums[right] != 0:
                usedBits ^= nums[left]
                left += 1
            
            usedBits |= nums[right]
            maxLen = max(maxLen, right - left + 1)

        return maxLen