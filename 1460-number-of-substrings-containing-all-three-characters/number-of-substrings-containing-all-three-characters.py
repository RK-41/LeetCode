class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # 11.03.25 potd
        ans, left, n = 0, 0, len(s)
        fr = {'a': 0, 'b': 0, 'c': 0}

        for right in range(n):
            fr[s[right]] += 1

            while fr['a'] > 0 and fr['b'] > 0 and fr['c'] > 0:
                ans += n - right
                fr[s[left]] -= 1
                left += 1

        return ans