class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        # 24.12.25 POTD
        total = sum(apple)
        if total == 0:
            return 0
            
        ans = 0
        capacity.sort(reverse=True)

        for c in capacity:
            total -= c
            ans += 1

            if total <= 0:
                break

        return ans