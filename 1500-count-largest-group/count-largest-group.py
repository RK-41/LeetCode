class Solution:
    def countLargestGroup(self, n: int) -> int:
        # 23.04.25
        ans = 0
        gr = {}
        mx = 1

        for x in range(1, n+1):
            xx = x
            sm = 0
            while x > 0:
                sm += x%10
                x //= 10
            if sm not in gr:
                gr[sm] = [sm]
            else:
                gr[sm].append(xx)
                mx = max(mx, len(gr[sm]))

        for x in gr:
            if len(gr[x]) == mx:
                ans += 1
        
        return ans
