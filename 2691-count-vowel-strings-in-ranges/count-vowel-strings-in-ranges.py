class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        # 02.01.25 POTD
        ans, vowels = [], ['a', 'e', 'i', 'o', 'u']
        n = len(words)
        cumSum = [0] * n
        if words[0][0] in vowels and words[0][-1] in vowels:
            cumSum[0] = 1 

        for i in range(1,n):
            cumSum[i] = cumSum[i-1]

            if words[i][0] in vowels and words[i][-1] in vowels:
                cumSum[i] += 1

        for l,r in queries:
            ans.append(cumSum[r] if l == 0 else (cumSum[r]-cumSum[l-1]))

        return ans
            
