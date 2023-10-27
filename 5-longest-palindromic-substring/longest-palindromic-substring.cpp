class Solution {
public:
    string longestPalindrome(string s) {
        // 27.10.23 potd
        // Mancher's Algorithm

        string T = "^#";

        for(char c: s){
            T += c;
            T += '#';
        }

        T += "$";

        int n = T.size();
        vector<int> P(n, 0);
        int C = 0, R = 0;

        for(int i=1; i<n-1; i++){
            P[i] = (R>i) ? min(R-i, P[2*C - i]) : 0;

            while(T[i+1+P[i]] == T[i-1-P[i]])
                P[i]++;

            if(i+P[i] > R){
                C = i;
                R = i + P[i];
            }
        }

        int max_len = *max_element(P.begin(), P.end());
        int center_idx = distance(P.begin(), find(P.begin(), P.end(), max_len));

        return s.substr((center_idx - max_len)/2, max_len);
    }
};