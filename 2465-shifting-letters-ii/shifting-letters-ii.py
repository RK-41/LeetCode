class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        # 05.01.25 poTD
        ans = ""
        n = len(s)
        diff = [0] * (n+1)

        for l, r, d in shifts:
            diff[l] += (1 if d == 1 else -1)
            diff[r+1] -= (1 if d == 1 else -1)

        for i in range(1,n+1):
            diff[i] += diff[i-1]

        for i in range(n):
            ascii = ord(s[i]) + diff[i]%26

            if ascii < 97:
                ascii += 26

            elif ascii > 122:
                ascii -= 26

            ans += chr(ascii)

        return ans
