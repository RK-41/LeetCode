class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        # 12.02.25 POTD
        ans = 0
        equal = {}

        for a in nums:
            sm = 0
            x = a
            while x>0:
                sm += (x%10)
                x //= 10

            prev = equal.get(sm, [])
            prev.append(a)
            equal[sm] = prev
        
        for gr in equal:
            if len(equal[gr]) == 1:
                continue

            lst = equal[gr]
            print(lst)
            mx1, mx2 = 0, 0

            for a in lst:
                if a >= mx1:
                    mx2 = mx1
                    mx1 = a
                elif a > mx2 and a < mx1:
                    mx2 = a

            ans = max(ans, mx1 + mx2)

        return ans if ans > 0 else -1
        