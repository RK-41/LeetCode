class Solution:
    def makeFancyString(self, s: str) -> str:
        # 21.07.25 POTD
        ans = ""
        cnt = 0
        prev = s[0]

        for c in s:
            if prev == c:
                cnt += 1
            else:
                cnt = 1
                prev = c
            
            if cnt < 3:
                ans += c
        
        return ans
