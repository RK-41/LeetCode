class Solution:
    def numberOfAlternatingGroups(self, colors: List[int], k: int) -> int:
        # 09.03.25 potd
        ans, l, n = 0, 0, len(colors)

        for r in range(n + k - 1):
            if r > 0 and colors[r%n] == colors[(r - 1)%n]:
                l = r
            
            if r - l + 1 >= k:
                ans += 1

        return ans