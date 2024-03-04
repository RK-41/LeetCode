class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // 04.03.24 POTD
        // APPROACH: Two-pointer
        // KEY IDEA: Sort the 'token' array

        if(tokens.size()==1){
            return tokens[0] <= power;
        }

        // Sort the array
        sort(tokens.begin(), tokens.end());

        int score=0, ans=0, i=0, j=tokens.size()-1;
        while(i<j){
            // Score as much as you can trading off with power
            while(tokens[i] <= power){
                power -= tokens[i++];
                score++;
                ans = max(ans, score);
            }

            // If you scored some, you can have some power;
            //  else it's time leave this power play
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