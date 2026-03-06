class Solution {
public:
    bool checkOnesSegment(string s) {
        // 06.03.26 POTD
        bool oz = false, one = s[0] == '1';

        for(int i=1; i<s.size(); i++){
            if(s[i] == '0' && s[i-1] == '1'){
                oz = true;
            } else if(s[i] == '1'){
                if(oz)  return false;
                one = true;
            }
        }

        return one;
    }
};