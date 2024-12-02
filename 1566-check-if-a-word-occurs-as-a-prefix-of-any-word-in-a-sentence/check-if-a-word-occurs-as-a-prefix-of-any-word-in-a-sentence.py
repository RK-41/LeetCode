class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # 02.12.24 POTD
        ans = -1
        words = sentence.split(' ')
        n, m = len(words), len(searchWord)

        for i in range(n):
            if words[i][:m] == searchWord:
                ans = i+1
                break

        return ans