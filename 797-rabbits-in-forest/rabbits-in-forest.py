class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        # 20.04.25 POTD
        ans = 0
        cnt = {}

        for x in answers:   
            cnt[x] = cnt.get(x, 0) + 1

        for x in cnt:
            gr = ceil(cnt[x] / (x + 1))
            ans += (gr * (x + 1))

        return ans