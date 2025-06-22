class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        # 22.06.25 POTD
        ans = []
        n = len(s)
        t = ''
        for i in range(0,n,k):
            ans.append(s[i:i+k])

        if len(ans[-1]) < k:
            ans[-1] = ans[-1] + (fill * (k - len(ans[-1])))
        
        return ans