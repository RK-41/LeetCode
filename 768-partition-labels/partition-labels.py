class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # 30.03.25 potd
        ans = []
        st, end = 0, 0
        lastOccur = {}

        for i, char in enumerate(s):
            lastOccur[char] = i

        for i, char in enumerate(s):
            end = max(end, lastOccur[char])

            if i == end:
                ans.append(end - st + 1)
                st = i + 1
            
        return ans