class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # 26.12.24 potd
        n = len(nums)
        sm = sum(nums)
        diff = sm-target

        if diff < 0 or diff%2 == 1: return 0

        diff /= 2
        @cache

        def f(j, sm):
            if j == 0: return 1 if sm == 0 else 0
            x = nums[j-1]
            ans = f(j-1, sm)

            if sm >= x:
                ans += f(j-1, sm-x)
            return ans
    
        return f(n, diff)