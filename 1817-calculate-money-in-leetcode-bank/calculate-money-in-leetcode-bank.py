class Solution:
    def totalMoney(self, n: int) -> int:
        # 25.10.25 POTD
        ans = 0
        nn = n // 7
        rem = n % 7
        a = 28
        d = 7
        
        # AP for complete weeks
        ans = (nn * (2 * a + (nn-1) * d)) // 2

        # AP for days in last week
        ans += (rem * (2 * (1+nn) + rem - 1)) // 2

        return ans