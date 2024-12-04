class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        # 04.12.24 potd
        srcLen, trgtLen = len(str1), len(str2)
        trgtChar = str2[0]
        srcIdx = trgtIdx = 0

        while srcIdx < srcLen and trgtIdx < trgtLen:
            srcChar = str1[srcIdx]

            if (srcChar == trgtChar or chr(ord(srcChar) + 1) == trgtChar or (srcChar == 'z' and trgtChar == 'a')):
                trgtIdx += 1

                if trgtIdx < trgtLen:
                    trgtChar = str2[trgtIdx]

            srcIdx += 1
        
        return trgtIdx == trgtLen