from collections import defaultdict
class Solution:
    def numEquivDominoPairs(self, doms: List[List[int]]) -> int:
        # 04.05.25 POTD
        ans = 0
        fr = {}
        n = len(doms)

        for i in range(n):
            x = tuple(sorted(doms[i]))
            fr[x] = fr.get(x, 0) + 1
        
        for p in fr:
            if fr[p] > 1:
                ans += (fr[p] * (fr[p] - 1) // 2)
        
        return ans