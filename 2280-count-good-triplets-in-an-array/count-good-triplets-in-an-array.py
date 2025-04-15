class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        # 15.04.25 potd
        total, n = 0, len(nums2)
        mp, st = {}, []

        for i, v in enumerate(nums1):
            mp[v] = i

        for x in nums2:
            idx = mp[x]
            left = bisect.bisect_left(st, idx)
            right = (n -1 - idx) - (len(st) - left)
            total += left * right
            bisect.insort(st, idx)

        return total