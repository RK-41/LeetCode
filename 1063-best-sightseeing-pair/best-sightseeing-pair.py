class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        # 27.12.24 POTD
        ans = 0
        n = len(values)
        maxValJRL = [0] * n # max value[j] - j right to left
        maxValJRL[n-1] = values[n-1] - (n-1)

        # Calculating max value of (values[j] - j) at ith position
        for i in range(n-2,-1,-1):
            maxValJRL[i] = max(values[i] - i, maxValJRL[i+1])

        # Finding max score
        for i in range(n-1):
            ans = max(ans, values[i] + i + maxValJRL[i+1])

        return ans

        # Optimal solution:
        # One pass from 1 to n-1
        # Use a single variable x to keep track of max (val[i] + i)
        # Update ans with max(ans, m + val[j] - j)