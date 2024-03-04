class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // 04.03.24 POTD
        // KEY IDEA: Sort the 'token' array
        if(tokens.size()==1){
            return tokens[0] <= power;
        }

        sort(tokens.begin(), tokens.end());

        int score=0, ans=0, i=0, j=tokens.size()-1;
        while(i<j){
            while(tokens[i] <= power){
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            }

            if(score > 0){
                score--;
                power += tokens[j--];
            } else {
                break;
            }
        }

        return ans;
    }
};