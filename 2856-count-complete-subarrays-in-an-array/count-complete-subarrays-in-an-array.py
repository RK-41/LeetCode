class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        # 24.04.25 Potd
        ans = 0
        fr = {}
        left = 0
        k = len(set(nums))

        for i in range(len(nums)):
            fr[nums[i]] = fr.get(nums[i], 0) + 1

            while len(fr) == k:
                ans += len(nums) - i
                fr[nums[left]] -= 1
                if fr[nums[left]] == 0:
                    del fr[nums[left]]
                left += 1

        return ans


