class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # 30.12.24 potd
        count = 0
        mod = 10**9 + 7
        ways = [0] * (high+1)
        ways[0] = 1

        for len in range(high + 1):
            if ways[len] == 0:
                continue

            if len + zero <= high:
                ways[len + zero] = (ways[len + zero] + ways[len]) % mod
            if len + one <= high:
                ways[len + one] = (ways[len + one] + ways[len]) % mod

        for i in range(low, high+1):
            count = (count + ways[i]) % mod

        return count
