class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        # 11.04.25 
        ans = 0

        for x in range(low, high+1):
            y = x
            ylen = 0
            tot = 0
            while y > 0:
                tot += (y % 10)
                y = y // 10
                ylen += 1

            if ylen % 2 == 1 or tot % 2 == 1: continue

            sm = 0
            y = x
            for i in range(ylen//2):
                sm += (y % 10)
                y //= 10
            
            if sm == tot // 2:
                ans += 1

        return ans
            
