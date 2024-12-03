class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        # 03.12.24 pOTd
        # APPROACH 1
        # revList = spaces[::-1]

        # for p in revList:
        #     s = s[:p] + " " + s[p:]

        # return s

        # Approach 2
        m, n = len(spaces), len(s)
        t = [' ']*(m+n)
        j = 0

        for i, c in enumerate(s):
            if j<m and i==spaces[j]:
                j += 1
            t[i+j] = s[i]

        return "".join(t)