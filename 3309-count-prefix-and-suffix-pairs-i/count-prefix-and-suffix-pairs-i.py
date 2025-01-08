class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        # 08.01.25 POTD
        def isPrefixAndSuffix(s1: str, s2: str):
            m, n = len(s1), len(s2)
            if m > n:
                return False

            return s1 == s2[:m] and s1 == s2[-m:]

        ans, wn = 0, len(words)
        for i in range(wn):
            for j in range(i+1, wn):
                if isPrefixAndSuffix(words[i], words[j]):
                    ans += 1
        
        return ans

            