class Solution:
    def maxScore(self, s: str) -> int:
        # 01.01.25 POTD
        ans = 0
        n = len(s)
        onesRTL = [0] * n
        onesRTL[n-1] = 1 if s[n-1] == '1' else 0
        zeros = 1 if s[0] == '0' else 0

        for i in range(n-2,-1,-1):
            onesRTL[i] = onesRTL[i+1] + (1 if s[i] == '1' else 0)

        for i in range(1,n):
            ans = max(ans, zeros + onesRTL[i])
            zeros += 1 if s[i] == '0' else 0

        return ans