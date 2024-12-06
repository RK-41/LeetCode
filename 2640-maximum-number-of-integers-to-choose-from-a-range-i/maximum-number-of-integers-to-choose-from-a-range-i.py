class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        # 06.12.24 POTD
        banned.sort()
        st = set(banned)
        ans, sum, i = 0, 0, 1

        while i <= n:
            if i not in st and sum + i <= maxSum:
                sum += i
                ans += 1
            i += 1

        return ans