class Solution:
    def mergeArrays(self, n1: List[List[int]], n2: List[List[int]]) -> List[List[int]]:
        # 02.03.25 POTD
        ans = []
        m, n = len(n1), len(n2)
        i, j = 0, 0

        while i < m or j < n:
            curr = []
            if i < m and j < n:
                if n1[i][0] == n2[j][0]:
                    curr = [n1[i][0], n1[i][1] + n2[j][1]]
                    i += 1
                    j += 1
                elif n1[i][0] < n2[j][0]:
                    curr = n1[i]
                    i += 1
                else:
                    curr = n2[j]
                    j += 1
            elif i < m:
                curr = n1[i]
                i += 1
            elif j < n:
                curr = n2[j]
                j += 1
            
            ans.append(curr)

        return ans