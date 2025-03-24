class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        # 24.03.25 potd
        meetings.sort()
        mergedM = []

        for meet in meetings:
            if not mergedM or meet[0] > mergedM[-1][1]:
                mergedM.append(meet)
            else:
                mergedM[-1][1] = max(mergedM[-1][1], meet[1])
            
        meetDays = 0

        for start, end in mergedM:
            meetDays += end - start + 1

        return days - meetDays
