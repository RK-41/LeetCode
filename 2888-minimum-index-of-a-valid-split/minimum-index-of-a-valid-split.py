class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        # 27.03.25 potd
        n = len(nums)
        cnt, xm = 0, 0

        for x in nums:
            if cnt == 0: xm = x
            cnt += (x == xm) * 2 - 1

        cntL, cntR, i = 0, 0, 0

        while i < n and cntL * 2 <= i:
            cntL += nums[i] == xm
            i += 1

        i -= 1
        for j in range(i+1, n):
            cntR += nums[j] == xm

        return i if cntR * 2 > (n-i-1) else -1