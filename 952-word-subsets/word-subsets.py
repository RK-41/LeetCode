class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        # 10.01.25 POTD
        ans = []
        count = {}

        for w in words2:
            temp = {}
            for c in w:
                temp[c] = temp.get(c,0) + 1
            
            for c in temp:
                count[c] = max(count.get(c,0), temp[c])

        for w in words1:
            temp = count.copy()

            for c in w:
                temp[c] = temp.get(c,0) - 1

            isSubset = True
            for c in temp:
                if temp[c] > 0:
                    isSubset = False
                    break
            
            if isSubset:
                ans.append(w)

        return ans