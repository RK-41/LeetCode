class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        # 22.11.24 potd
        count = defaultdict(int)

        for row in matrix:
            row_key = tuple(row)

            if row[0]:
                row_key = tuple([0 if n else 1 for n in row])
            
            count[row_key] += 1
        
        return max(count.values())