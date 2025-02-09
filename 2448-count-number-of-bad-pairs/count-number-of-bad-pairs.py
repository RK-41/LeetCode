class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        # 09.02.25 potd
        fr = {}
        goodPairs = 0

        for i, num in enumerate(nums):
            key = num - i
            goodPairs += fr.get(key, 0)
            fr[key] = fr.get(key, 0) + 1

        n = len(nums)

        return (n * (n-1)) // 2 - goodPairs