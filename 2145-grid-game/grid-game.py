class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        # 21.01.25 potd
        ans = float('inf')
        r1sum = sum(grid[0])
        r2sum = 0

        for i in range(len(grid[0])):
            r1sum -= grid[0][i]
            ans = min(ans, max(r1sum, r2sum))
            r2sum += grid[1][i]

        return ans