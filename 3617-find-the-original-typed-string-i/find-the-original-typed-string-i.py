class Solution:
    def possibleStringCount(self, word: str) -> int:
        # 01.07.25 POTD
        ans = 0
        prev = word[0]

        for x in word:
            if prev == x:
                ans += 1
            else:
                prev = x
        
        return ans