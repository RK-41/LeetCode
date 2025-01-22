class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        # 22.01.25 potd
        r = len(isWater)
        c = len(isWater[0])
        height = [[float('inf')] * c for _ in range(r)]

        for i in range(r):
            for j in range(c):
                if isWater[i][j] == 1:
                    height[i][j] = 0
                else:
                    if i>0:
                        height[i][j] = min(height[i][j], height[i-1][j] + 1)
                    if j>0:
                        height[i][j] = min(height[i][j], height[i][j-1] + 1)

        for i in range(r-1, -1, -1):
            for j in range(c-1, -1, -1):
                if i<r-1:
                    height[i][j] = min(height[i][j], height[i+1][j] + 1)
                if j<c-1:
                    height[i][j] = min(height[i][j], height[i][j+1] + 1)

        return height 