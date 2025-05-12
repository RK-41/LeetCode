class Solution:
    def findEvenNumbers(self, dig: List[int]) -> List[int]:
        # 12.05.25 POTD
        ans = set()
        n = len(dig)

        for i in range(n):
            if dig[i] == 0:
                continue

            for j in range(n):
                if i == j:  continue

                for k in range(n):
                    if k == j or k == i:    continue

                    if dig[k]%2 == 0:
                        ans.add(dig[i]*100 + dig[j]*10 + dig[k])
            
        return sorted(ans)