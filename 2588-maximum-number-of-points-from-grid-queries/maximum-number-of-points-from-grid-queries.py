from queue import PriorityQueue

class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        # 28.03.25 potd
        rows, cols = len(grid), len(grid[0])
        dir = [(0,1), (1,0), (0,-1), (-1,0)]
        
        sortedQ = sorted([(val, idx) for idx, val in enumerate(queries)])
        res = [0] * len(queries)

        hp = PriorityQueue()
        vis = [[False] * cols for _ in range(rows)]

        hp.put((grid[0][0], 0, 0))
        vis[0][0] = True
        pts = 0

        for qv, qi in sortedQ:
            while not hp.empty() and hp.queue[0][0] < qv:
                _, row, col = hp.get()
                pts += 1

                for dr, dc in dir:
                    nr, nc = row+dr, col+dc

                    if (0 <= nr < rows and 0 <= nc < cols) and not vis[nr][nc]:
                        hp.put((grid[nr][nc], nr, nc))
                        vis[nr][nc] = True
            
            res[qi] = pts
        
        return res