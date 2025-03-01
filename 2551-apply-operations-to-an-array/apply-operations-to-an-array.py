class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        # 01.03.25 POTD
        ans = []
        n = len(nums)
        idx = 0

        for i in range(n-1):
            if nums[i] == 0:
                continue
            if nums[i] == nums[i+1]:
                ans.append(nums[i] * 2)
                nums[i + 1] = 0
            else:
                ans.append(nums[i])

        if nums[-1] > 0:
            ans.append(nums[-1])
            
        while len(ans) < len(nums):
            ans.append(0)
            
        return ans