class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        # 27.07.25 POTD
        ans = 0
        arr = []
        prev = -1

        for x in nums:
            if x != prev:
                arr.append(x)
                prev = x
        
        for i in range(1, len(arr)-1):
            if (arr[i-1] < arr[i] > arr[i+1]) or (arr[i-1] > arr[i] < arr[i+1]):
                ans += 1
        
        return ans