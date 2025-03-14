class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        # 14.03.25 potd
        ans = 0
        left, right = 1, max(candies)

        while left <= right:
            mid = (left + right)//2
            child = sum(pile // mid for pile in candies)

            if child >= k:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans