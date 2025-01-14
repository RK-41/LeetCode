class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        # 14.01.25 POTD
        ans = []
        countA, countB = {}, {}
        n = len(A)
        count = 0

        for i in range(n):
            countA[A[i]] = countA.get(A[i], 0) + 1
            countB[B[i]] = countB.get(B[i], 0) + 1

            count += min(countA[A[i]], countB.get(A[i],0))
            if A[i] != B[i]:
                count += min(countA.get(B[i],0), countB[B[i]])
                
            ans.append(count)
        
        return ans