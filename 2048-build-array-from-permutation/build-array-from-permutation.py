class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        # 06.05.25 POTD
        return [nums[nums[i]] for i in range(len(nums))]