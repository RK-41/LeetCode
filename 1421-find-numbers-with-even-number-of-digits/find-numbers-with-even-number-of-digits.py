class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        # 30.04.25 POTD
        ans = 0

        for x in nums:
            if 9<x<100 or 999<x<10000 or 99999<x<1000000:
                ans += 1
        
        return ans