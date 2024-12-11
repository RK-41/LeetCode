class Solution:
    def maximumBeauty(self, nums: List[int], k: int) -> int:
        # 11.12.24 potd
        events = []
        for num in nums:
            events.append((num-k,1)) # start of range
            events.append((num+k+1,-1)) # end of range (exclusive)

        # Sort events by value, and in case of tie, by type of event
        events.sort()

        # Use a sweep line approach to calculate the max overlap
        maxBeauty = 0
        currCnt = 0

        for val, eff in events:
            currCnt += eff
            maxBeauty = max(maxBeauty, currCnt)

        return maxBeauty