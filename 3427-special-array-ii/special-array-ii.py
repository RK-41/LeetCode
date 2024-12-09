class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        # 09.12.24 
        ans = []
        n = len(nums)
        prefix = [0]*n  # prefix arr to cound special pairs

        # Building prefix arr
        for i in range(1,n):
            prefix[i] = prefix[i-1]
            if (nums[i-1]%2 == 0 and nums[i]%2 == 0) or (nums[i-1]%2 == 1 and nums[i]%2 == 1):
                prefix[i] += 1

        # Processing queries
        for left, right in queries:
            special = prefix[right] - (prefix[left] if left > 0 else 0)
            ans.append(special == 0)

        return ans