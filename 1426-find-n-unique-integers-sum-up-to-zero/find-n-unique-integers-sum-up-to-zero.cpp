class Solution {
public:
    vector<int> sumZero(int n) {
        // 07.09.25 POTD
        vector<int> ans(n, 0);
        int half = n/2;
        int oe = n%2;

        for(int i=oe; i<half+oe; i++){
            ans[half + i] = i + 1;
            if(oe == 1)
                ans[half - i] = -(i + 1);
            else
                ans[half - i - 1] = -(i + 1);
        }

        return ans;
    }
};