class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        # 15.12.24 POTD

        # APPROACH 1
        # ans, ratio, n = 0, 0, len(classes)
        # e = extraStudents

        # for p, t in classes:
        #     ratio += p/t

        # for p, t in classes:
        #     curr = ratio - (p/t) + ((p+e)/(t+e))
        #     ratio = max(ratio, curr)

        # return ratio/n

        # Approach 2
        import heapq

        def gain(pass_, total):
            return (pass_ + 1) / (total + 1) - pass_/total

        maxHeap = []
        sm = 0.0

        for p, t in classes:
            sm += p/t
            heapq.heappush(maxHeap, (-gain(p,t), p, t))

        for _ in range(extraStudents):
            currGain, p, t = heapq.heappop(maxHeap)
            sm -= p/t
            p += 1
            t += 1
            sm += p/t
            heapq.heappush(maxHeap, (-gain(p,t), p, t))

        return sm/len(classes)
        