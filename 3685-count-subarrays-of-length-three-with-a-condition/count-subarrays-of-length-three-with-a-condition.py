class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        # 27.04.25 POTD
        ans = 0
        for i in range(1,len(nums)-1):
            if nums[i-1] + nums[i+1] == nums[i] / 2:
                ans += 1

        return ans