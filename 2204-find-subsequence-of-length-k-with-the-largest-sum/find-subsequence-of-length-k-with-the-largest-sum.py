class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        # 28.06.25 POTD
        ans = []
        new = sorted(nums)[len(nums) - k:]
        fr = {}

        for x in new:
            fr[x] = fr.get(x, 0) + 1

        for x in nums:
            if fr.get(x, 0) > 0:
                ans.append(x)
                fr[x] -= 1
        
        return ans