class Solution:
    def maxDifference(self, s: str) -> int:
        # 10.06.25 (POTD)
        fr = {}
        ans = 0
        omin, emin = [float('inf')] * 2
        omax, emax = [0] * 2
        
        for c in s:
            fr[c]  = fr.get(c, 0) + 1

        for p in fr:
            f = fr[p]
            if f%2 == 1:
                omin = min(omin, f)
                omax = max(omax, f)
            else:
                emin = min(emin, f)
                emax = max(emax, f)

        return max((omin - emax), (omax - emin))