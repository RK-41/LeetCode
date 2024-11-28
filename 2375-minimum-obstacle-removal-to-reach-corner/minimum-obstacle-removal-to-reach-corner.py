class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        # 28.11.24 potd
        m, n = len(grid), len(grid[0])
        dist = [[float('inf')]*n for _ in range(m)]
        dq = collections.deque()

        dist[0][0] = 0
        dq.appendleft((0,0))
        directions = [(0,1), (1,0), (0,-1), (-1,0)]

        while dq:
            x, y = dq.popleft()
            for dx, dy in directions:
                nx, ny = x+dx, y+dy
                if 0 <= nx < m and 0 <= ny < n:
                    newDist = dist[x][y] + grid[nx][ny]
                    if newDist < dist[nx][ny]:
                        dist[nx][ny] = newDist
                        if grid[nx][ny] == 0:
                            dq.appendleft((nx,ny))
                        else:
                            dq.append((nx,ny))

        return dist[m-1][n-1]