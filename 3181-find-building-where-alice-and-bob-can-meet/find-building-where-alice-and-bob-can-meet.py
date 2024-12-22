class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        # 22.12.24 potd
        n = len(heights)
        st = [[0] * 20 for _ in range(n)]
        log = [-1] * (n+1)
        
        for i in range(1, n+1):
            log[i] =  log[i >> 1] + 1
        
        for i in range(n):
            st[i][0] = heights[i]

        for i in range(1, 20):
            for j in range(n):
                if j + (1 << i) <= n:
                    st[j][i] = max(st[j][i-1], st[j + (1 << ( i-1))][i-1])

        def ask(l, r):
            k = log[r-l+1]
            return max(st[l][k], st[r - (1 << k) + 1][k])
        
        ans = []
        for l, r in queries:
            if l>r:
                l, r = r, l
            if l==r:
                ans.append(l)
                continue
            if heights[r] > heights[l]:
                ans.append(r)
                continue
            
            maxH = max(heights[r], heights[l])
            left, right = r+1, n
            while left < right:
                mid = (left+right)//2
                if ask(r+1, mid) > maxH:
                    right = mid
                else:
                    left = mid+1
            
            ans.append(left if left != n else -1)
        
        return ans