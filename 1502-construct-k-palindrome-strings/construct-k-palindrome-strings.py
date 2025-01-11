class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # 11.01.25 potd
        if len(s) < k:
            return False

        ss = sorted(s)
        oddCount = 0
        i, n = 0, len(ss)

        while i<n:
            char = ss[i]
            count = 0

            while i<n and ss[i] == char:
                count += 1
                i += 1
            
            if count%2 == 1:
                oddCount += 1
        
        return oddCount <= k