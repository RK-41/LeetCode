class Solution {
public:
    int binaryGap(int n) {
        // 22.02.26 POTD
        int ans = 0, one = -1, i = 0;
        string s = bitset<32>(n).to_string();

        while(i<s.size()){
            while(one > -1 && s[i] == 0){
                i++;
            }
            if(s[i] == '1'){
                if(one > -1)    ans = max(ans, i-one);
                one = i;
            }
            i++;
        }

        return ans;
    }
};