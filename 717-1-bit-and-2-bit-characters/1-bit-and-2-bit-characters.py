class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        # 18.11.25 potd
        i = 0
        while i < len(bits) - 1:
            i += (bits[i] + 1)
        
        return i == len(bits) - 1