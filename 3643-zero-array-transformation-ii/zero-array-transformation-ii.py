class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        # 13.02.25 potd
        n = len(nums)
        sumVal = 0
        qrs = 0
        diffArr = [0] * (n+1)

        for i in range(n):
            while sumVal + diffArr[i] < nums[i]:
                qrs += 1
                if qrs > len(queries):
                    return -1
                
                left, right, val = queries[qrs - 1]
                if right >= i:
                    diffArr[max(left, i)] += val
                    if right + 1 < len(diffArr):
                        diffArr[right + 1] -= val
                
            sumVal += diffArr[i]

        return qrs