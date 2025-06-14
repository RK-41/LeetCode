class Solution:
    def minMaxDifference(self, num: int) -> int:
        # 14.06.25 POTD
        mx = mv = ''
        mxv = mnv = ''
        sn = str(num)
        
        for c in sn:
            if c < '9':
                mx = c
                break

        for c in sn:
            if c > '0':
                mn = c
                break
            
        for c in sn:
            mxv += ('9' if c == mx else c)
            mnv += ('0' if c == mn else c)
        
        return int(mxv) - int(mnv)
