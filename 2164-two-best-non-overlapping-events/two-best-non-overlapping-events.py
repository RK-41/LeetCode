class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        # 08.12.24
        ans = 0
        n = len(events)

        # Sorting events by their starting time
        events.sort(key=lambda x: x[0])

        # Suffix arr for max event val from each event onward
        suffixMax = [0]*n
        suffixMax[n-1] = events[n-1][2]

        # Populating suffix arr
        for i in range(n-2,-1,-1):
            suffixMax[i] = max(events[i][2], suffixMax[i+1])

        # For each events, finding next event that starts after if ends
        for i in range(n):
            left, right = i+1, n-1
            nextIdx = -1

            while left <= right:
                mid = left + (right-left)//2
                
                if events[mid][0] > events[i][1]:
                    nextIdx = mid
                    right = mid-1
                else:
                    left = mid+1
            
            # Updating ans if a valid event is found
            if nextIdx != -1:
                ans = max(ans, events[i][2] + suffixMax[nextIdx])
            
            # Considering the case where only current event's val can be taken
            ans = max(ans, events[i][2])

        return ans
        