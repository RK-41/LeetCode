class Solution:
    def maxMatrixSum(self, mat: List[List[int]]) -> int:
        # 24.11.24 potd
        """
        :type mat: List[List[int]]
        :rtype: int
        """

        minVal = float('inf')
        totSum = 0
        negCnt = 0

        for row in mat:
            for val in row:
                if val < 0:
                    negCnt += 1
                
                absVal = abs(val)
                minVal = min(minVal, absVal)
                totSum += absVal

        if negCnt % 2 == 0:
            return totSum

        return totSum - 2 * minVal