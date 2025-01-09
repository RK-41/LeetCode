class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        # 09.01.25 POTD
        ans = 0
        prefLen = len(pref
        )
        for w in words:
            if prefLen > len(w):
                continue

            if pref == w[:prefLen]:
                ans += 1
        
        return ans