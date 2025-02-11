class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # 11.02.25 POTD
        ans = ''
        slist = list(s)
        plen = len(part)

        for c in s:
            ans = ans + c

            if len(ans) >= plen:
                sub = ans[len(ans) - plen:]

                if sub == part:
                    ans = ans[:len(ans) - plen]
        
        return ans
