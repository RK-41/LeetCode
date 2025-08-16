class Solution:
    def maximum69Number (self, num: int) -> int:
        # 16.08.25 POTD
        ex, x, y, z = 1, 0, num, 0

        while y > 0:
            d = y%10
            y //= 10
            if d == 6:
                x = ex
            z += (ex * d)
            ex *= 10
        
        z += (3 * x)
        return z