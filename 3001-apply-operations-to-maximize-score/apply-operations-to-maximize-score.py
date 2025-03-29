import heapq

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        # 29.03.25 potd
        mod = 10**9 + 7

        # Implement sieve algo
        maxNum = max(nums)
        spf = list(range(maxNum + 1))

        for i in range(2, int(maxNum ** 0.5) + 1):
            if spf[i] == i: # i is prime
                for j in range(i*i, maxNum + 1, i):
                    if spf[j] == j:
                        spf[j] = i
        
        # Calc prime score for each number
        def getPrimeScore(x):
            if x == 1:  return 0

            factors = set()
            while x > 1:
                factors.add(spf[x])
                x = x // spf[x]
            
            return len(factors)
        
        primeScores = [getPrimeScore(x) for x in nums]

        # Find subarr counts using monotonic stacks
        n = len(nums)
        left = [-1] * n
        right = [n] * n
        stk = []

        # Find next greater element to the left
        for i in range(n):
            while stk and primeScores[stk[-1]] < primeScores[i]:
                stk.pop()
            
            if stk:
                left[i] = stk[-1]
            
            stk.append(i)

        stk = []
        # Find next greater or equal element ot the right
        for i in range(n-1, -1, -1):
            while stk and primeScores[stk[-1]] <= primeScores[i]:
                stk.pop()
            
            if stk:
                right[i] = stk[-1]
            
            stk.append(i)

        # Calc counts for each element
        counts = [(right[i] - i) * (i - left[i]) for i in range(n)]

        # Use Max-heap ot select top elements
        # Implement max-heap using min-heap with negative values
        heap = []
        for i in range(n):
            heapq.heappush(heap, (-nums[i], counts[i]))
        
        res = 1
        while k > 0 and heap:
            num, cnt = heapq.heappop(heap)
            curr = -num
            use = min(cnt, k)
            res = (res * pow(curr, use, mod)) % mod
            k -= use
        
        return res

# \U0001f680\U0001f525