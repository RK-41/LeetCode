class Solution:
    def smallestNumber(self, pattern: str) -> str:
        # 18.02.25 potd
        n = len(pattern)
        ans = ''
        stk = []

        for i in range(n+1):
            stk.append(i+1)

            if i == n or pattern[i] == 'I':
                while stk:
                    ans += str(stk.pop())

        return ans