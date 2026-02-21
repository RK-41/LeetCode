class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // 21.02.26 POTD
        int ans = 0;
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 29, 31};

        while(left <= right){
            int s = __builtin_popcount(left);
            ans += st.count(s);
            left++;
        }

        return ans;
    }
};