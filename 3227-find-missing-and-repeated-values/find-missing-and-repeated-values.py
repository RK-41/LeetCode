class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        # 06.03.25 POTD
        ans = [0, 0]
        fr = {}
        n = len(grid)

        for lst in grid:
            for i in lst:
                fr[i] = fr.get(i, 0) + 1
                if fr[i] == 2:
                    ans[0] = i

        for i in range(n*n):
            if i+1 not in fr:
                ans[1] = i+1

        return ans

