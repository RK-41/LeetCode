class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        # 10.05.25 POTD
        s1, s2 = sum(nums1), sum(nums2)
        z1, z2 = nums1.count(0), nums2.count(0)

        if z1 == 0 and z2 == 0 and s1 != s2:
            return -1

        if z1 == 0 and z2 > 0:
            if s1 < s2 + z2:
                return -1
        
        if z1 > 0 and z2 == 0:
            if s1 + z1 > s2:
                return -1

        return max(s1 + z1, s2 + z2)