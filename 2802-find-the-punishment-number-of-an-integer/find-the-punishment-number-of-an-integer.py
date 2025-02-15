class Solution:
    def punishmentNumber(self, n: int) -> int:
        # 15.02.25 potd
        ans = 0
        arr = [1, 9, 10, 36, 45, 55, 82, 91, 99, 100, 235, 297, 369, 370, 379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000]

        for x in arr:
            if x <= n:
                ans += x * x
            else:
                break

        return ans