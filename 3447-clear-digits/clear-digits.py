class Solution:
    def clearDigits(self, s: str) -> str:
        # 10.02.25 POTD
        ans = []

        for c in s:
            if c in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
                ans.pop()
            else:
                ans.append(c)

        return ''.join(ans)