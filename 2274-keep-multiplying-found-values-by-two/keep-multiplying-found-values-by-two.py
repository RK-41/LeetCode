class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        # 19.11.25 POTD
        st = set(nums)
        org = original

        while org in st:
            org *= 2

        return org