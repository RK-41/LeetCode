class Solution:
    def doesValidArrayExist(self, derived: List[int]) -> bool:
        # 17.01.25 potd
        return reduce(xor, derived) == 0
        