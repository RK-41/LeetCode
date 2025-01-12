class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        # 12.01.25 potd
        n = len(s)
        if n%2 == 1:
            return False

        openIndices = []
        unlockedIndices = []

        for i in range(n):
            if locked[i] == '0':
                unlockedIndices.append(i)
            elif s[i] == '(':
                openIndices.append(i)
            elif s[i] == ')':
                if openIndices:
                    openIndices.pop()
                elif unlockedIndices:
                    unlockedIndices.pop()
                else:
                    return False
        
        while openIndices and unlockedIndices and openIndices[-1] < unlockedIndices[-1]:
            openIndices.pop()
            unlockedIndices.pop()

        if not openIndices and unlockedIndices:
            return len(unlockedIndices)%2 == 0

        return not openIndices

            