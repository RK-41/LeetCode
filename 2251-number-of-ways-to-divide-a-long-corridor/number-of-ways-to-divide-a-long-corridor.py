class Solution(object):
    def numberOfWays(self, corridor):
        # 14.12.25 potd
        mod = 10**9 + 7
        s0 = s1 = 0; s2 = 1
        for c in corridor:
            if c == 'S': s0, s1, s2 = s1, s2, s1
            else: s2 = (s2 + s0) % mod
        return s0