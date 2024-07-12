class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // 12.07.24 potd
        int ans = 0, topScore, botScore;
        string top, bot;

        if(y > x){
            top = "ba";
            topScore = y;
            bot = "ab";
            botScore = x;
        } else {
            top = "ab";
            topScore = x;
            bot = "ba";
            botScore = y;
        }

        ans += removePairs(s, top) * topScore;
        ans += removePairs(s, bot) * botScore;

        return ans;
    }

    int removePairs(string& s, string target){
        int writeIdx = 0, count = 0;
        for(char c: s){
            s[writeIdx] = c;
            writeIdx++;

            if(writeIdx >= 2 && s[writeIdx-1] == target[1] && s[writeIdx-2] == target[0]){
                count++;
                writeIdx -= 2;
            }
        }

        s.resize(writeIdx);

        return count;

    }
};