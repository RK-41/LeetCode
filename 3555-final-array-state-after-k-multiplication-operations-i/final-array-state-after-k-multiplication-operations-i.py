class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        # 16.12.24 POTD
        if multiplier == 1:
            return nums

        for _ in range(k):
            minIdx = 0
            for i in range(len(nums)):
                minIdx = i if nums[i] < nums[minIdx] else minIdx

            nums[minIdx] = nums[minIdx]*multiplier

        return nums