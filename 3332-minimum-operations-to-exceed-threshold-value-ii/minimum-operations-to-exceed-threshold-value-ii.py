from queue import PriorityQueue

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        # 13.02.25 POTD
        ans = 0
        q = PriorityQueue()

        for x in nums: q.put(x)

        while q:
            x = q.get()
            if x >= k or not q:  break
            y = q.get()

            q.put(x*2 + y)
            ans += 1

        return ans
