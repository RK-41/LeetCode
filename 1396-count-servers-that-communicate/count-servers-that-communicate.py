class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        # 23.01.25 POTD
        ans = 0
        st = set()
        m, n = len(grid), len(grid[0])

        for i in range(m):
            temp = set()
            for j in range(n):
                if grid[i][j] == 1:
                    temp.add((i,j))

            if len(temp) > 1:
                st.update(temp)

        for j in range(n):
            temp = set()
            for i in range(m):
                if grid[i][j] == 1:
                    temp.add((i,j))
            
            if len(temp) > 1:
                st.update(temp)

        return len(st)
