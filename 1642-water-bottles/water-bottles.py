class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        # 01.10.25 POTD
        ans = 0
        emp = 0
        nb, ne = numBottles, numExchange

        while nb > 0:
            ans += nb
            nb2 = (emp + nb) // ne
            emp = (emp + nb) % ne
            nb = nb2
            print(nb, emp)
        
        return ans