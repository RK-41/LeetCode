class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        # 28.12.24 potd
        n = len(nums)
        s1 = sum(nums[:k])
        s2 = sum(nums[k:2*k])
        s3 = sum(nums[2*k:3*k])

        mx1 = s1
        mx12 = s1 + s2
        mx123 = s1 + s2 + s3

        idx1 = 0
        idx12_1 = 0
        idx12_2 = k
        ans = [0, k, 2*k]

        for i in range(1, n-3*k+1):
            s1 = s1 - nums[i-1] + nums[i+k-1]
            s2 = s2 - nums[i+k-1] + nums[i+2*k-1]
            s3 = s3 - nums[i+2*k-1] + nums[i+3*k-1]

            if s1 > mx1:
                mx1 = s1
                idx1 = i

            if mx1 + s2 > mx12:
                mx12 = mx1 + s2
                idx12_1 = idx1
                idx12_2 = i + k 
            
            if mx12 + s3 > mx123:
                mx123 = mx12 + s3
                ans = [idx12_1, idx12_2, i+2*k]
        
        return ans