class Solution:
    def check(self, nums: List[int]) -> bool:
        # 02.02.25 POTD
        breakFound = False
        n = len(nums)
        i = 1

        while i < n:
            if nums[i-1] <= nums[i]:
                i += 1
            elif not breakFound:
                breakFound = True
                i += 1
            else:
                return False
            
        if breakFound and nums[0] < nums[-1]:
            return False
        
        return True