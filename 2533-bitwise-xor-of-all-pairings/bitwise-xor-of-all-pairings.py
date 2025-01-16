class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        # 16.01.25 POTD
        xr1, xr2, m, n = 0, 0, len(nums1), len(nums2)

        if m%2 != 0:
            for a in nums2:
                xr2 ^= a
        
        if n%2 != 0:
            for a in nums1:
                xr1 ^= a

        return xr1 ^ xr2