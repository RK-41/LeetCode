class Solution {
public:
    int longestBalanced(string s) {
        // 12.02.26 potd
        int fr[26] = {0};
        int cnt = 1, n = s.size();

        for(int l=0; l<n; l++){
            memset(fr, 0, sizeof(fr));
            int uniq = 0, mxf = 0, cntmx = 0;

            for(int r=l; r<n; r++){
                int f = ++fr[s[r] - 'a'];
                uniq += (f == 1);
                const bool gr = f > mxf, eq = f == mxf, less = !(gr|eq);
                mxf = (-gr & f) + (-!gr & mxf);
                cntmx = (-gr & 1) + (-eq & (cntmx + 1)) + (-less & cntmx);
                const bool need = (uniq == cntmx & cnt < r - l + 1);
                cnt = (-need & (r - l + 1)) + (-!need & cnt);
            }
        }

        return cnt;
    }
};