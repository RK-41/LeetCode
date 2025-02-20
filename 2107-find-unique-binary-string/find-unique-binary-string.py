class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        # 20.02.25 POTD
        n = len(nums)
        binary = ['0'] * n
        st = set(nums)

        def back(idx):
            nonlocal binary, st, n
            if idx == n:    return '-1'

            b = ''.join(binary)
            if b not in st:
                return b

            if binary[idx] == '1':  return back(idx + 1)
            
            binary[idx] = '1'
            res = back(idx)

            if res != '-1': return res

            binary[idx] = '0'
            return back(idx + 1)

        return back(0)