class Solution:
    def maxScore(self, s: str) -> int:
        # 01.01.25 POTD
        ans = 0
        ones = 0
        zeros = 1 if s[0] == '0' else 0
        n = len(s)

        for i in range(n-1,0,-1):
            ones += int(s[i])

        for i in range(1,n):
            ans = max(ans, zeros + ones)
            zeros += 1 if s[i] == '0' else 0
            ones -= int(s[i])

        return ans