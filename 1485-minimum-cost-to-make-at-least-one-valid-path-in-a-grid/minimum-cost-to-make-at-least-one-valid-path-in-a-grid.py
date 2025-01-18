class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        # 18.01.25 potd
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        m, n = len(grid), len(grid[0])

        # Init the minCost matrix with a larg value
        minCost = [[float('inf')] * n for _ in range(m)]
        minCost[0][0] = 0

        # Deque for 0-1 BFS
        dq = deque([(0,0)])

        # Dir: right, left, down, up
        dir = [(0,1), (0,-1), (1,0), (-1,0)]

        while dq:
            r, c = dq.popleft()

            # Visit adj cells
            for i, (dr, dc) in enumerate(dir):
                nr, nc = r + dr, c + dc
                cost = 1 if grid[r][c] != i+1 else 0

                if 0 <= nr < m and 0 <= nc < n and minCost[r][c] + cost < minCost[nr][nc]:
                    minCost[nr][nc] = minCost[r][c] + cost

                    # Add to deque based on cost
                    if cost == 1:
                        dq.append((nr, nc))
                    else:
                        dq.appendleft((nr,nc))
            
        # Return min cost to reach grid[m-1][n-1]
        return minCost[m-1][n-1]