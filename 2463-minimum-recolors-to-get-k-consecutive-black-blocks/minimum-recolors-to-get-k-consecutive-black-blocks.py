class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        # 08.03.25 POTD
        if len(blocks) == 1:    return 1 if blocks[0] == 'W' else 0

        ans, n = len(blocks), len(blocks)
        currCount = [0] * n
        if blocks[0] == 'W':    currCount[0] = 1 

        for i in range(1,n):
            currCount[i] = currCount[i-1] + (1 if blocks[i] == 'W' else 0)
        
        for i in range(k-1, n):
            ans = min(ans, currCount[i] - (currCount[i-k] if i >= k else 0))

        return ans