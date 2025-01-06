class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        # 06.01.25 potd
        n = len(boxes)
        dist = [0] * n
        prefixCnt = 0
        prefixSm = 0

        for i in range(n):
            dist[i] = prefixCnt * i - prefixSm
            if boxes[i] == '1':
                prefixCnt += 1
                prefixSm += i

        suffixCnt = 0
        suffixSm = 0

        for i in range(n-1,-1,-1):
            dist[i] += suffixSm - suffixCnt * i
            if boxes[i] == '1':
                suffixCnt += 1
                suffixSm += i

        return dist
