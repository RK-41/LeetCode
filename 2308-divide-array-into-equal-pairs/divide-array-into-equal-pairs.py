class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # 17.03.25 POTD
        fr = {}

        for x in nums:
            fr[x] = fr.get(x, 0) + 1
        
        for x in fr:
            if fr[x] % 2 == 1:
                return False

        return True