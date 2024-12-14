class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        # 14.12.24 potd
        ans, left, n = 0, 0, len(nums)
        minD, maxD = deque(), deque()

        for right in range(n):
            while minD and nums[minD[-1]] >= nums[right]: minD.pop()
            while maxD and nums[maxD[-1]] <= nums[right]: maxD.pop()
            minD.append(right)
            maxD.append(right)

            while nums[maxD[0]] - nums[minD[0]] > 2:
                left += 1
                if minD[0] < left: minD.popleft()
                if maxD[0] < left: maxD.popleft()

            ans += right - left + 1

        return ans

        