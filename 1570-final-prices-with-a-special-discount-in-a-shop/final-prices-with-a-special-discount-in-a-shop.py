class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        # 18.12.24 POTD
        n = len(prices)
        ans = prices
        minPriceRTL = [0]*n
        minPriceRTL[-1] = prices[-1]

        for i in range(n-2,0):
            minPriceRTL[i] = min(minPriceRTL[i], minPriceRTL[i+1])

        for i in range(n-1):
            if prices[i] < minPriceRTL[i+1]:
                continue

            for j in range(i+1,n):
                if prices[i] >= prices[j]:
                    ans[i] -= prices[j]
                    break

        return ans