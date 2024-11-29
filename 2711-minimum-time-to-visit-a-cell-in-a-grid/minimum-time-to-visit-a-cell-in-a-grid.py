class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        # 29.11.24 potd
        if grid[1][0] > 1 and grid[0][1] > 1:
            return -1

        row, col = len(grid), len(grid[0])

        def isOutside(i, j):
            return i<0 or i>=row or j<0 or j>=col

        def idx(i, j):
            return i*col + j

        n = row*col

        time = [2**31] * n
        pq = [0]
        time[0] = 0

        while pq:
            tij = heappop(pq)
            t, ij = tij >> 32, tij & ((1 << 30) - 1)
            i, j = divmod(ij, col)
            if i == row - 1 and j == col - 1:
                return t

            for di, dj in [(0,1), (1,0), (0,-1), (-1,0)]:
                r, s = i + di, j + dj
                if isOutside(r,s):
                    continue

                w = 0 if (grid[r][s] - t) & 1 else 1
                nextTime = max(t+1, grid[r][s] + w)

                rs = idx(r,s)
                if nextTime < time[rs]:
                    time[rs] = nextTime
                    heappush(pq, (nextTime << 32) + rs)

        return -1