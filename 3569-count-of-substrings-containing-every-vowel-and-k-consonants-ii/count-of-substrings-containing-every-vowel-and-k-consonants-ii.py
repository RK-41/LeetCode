class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        # 10.03.25 potd
        fr = [{}, {}]
        for v in 'aeiou':
            fr[0][v] = 1

        res, currK, vowels, extraLeft, left = 0, 0, 0, 0, 0

        for right, rChar in enumerate(word):
            if rChar in fr[0]:
                fr[1][rChar] = fr[1].get(rChar, 0) + 1
                if fr[1][rChar] == 1:
                    vowels += 1
            else:
                currK += 1

            while currK > k:
                lChar = word[left]
                if lChar in fr[0]:
                    fr[1][lChar] -= 1
                    if fr[1][lChar] == 0:
                        vowels -= 1
                else:
                    currK -= 1

                left += 1
                extraLeft = 0
            
            while vowels == 5 and currK == k and left < right and word[left] in fr[0] and fr[1][word[left]] > 1:
                extraLeft += 1
                fr[1][word[left]] -= 1
                left += 1
            
            if currK == k and vowels == 5:
                res += (1 + extraLeft)

        return res