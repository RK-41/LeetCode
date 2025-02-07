class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // 07.02.25 POTD
        vector<int> ans;
        unordered_map<int,int> ballColor, colorFr;
        // ballColor: current color of ball
        // colorFr: Freq of use of color at present

        for(auto& q: queries){
            // Decrementing count of previous color of current ball
            int prevColor = ballColor[q[0]];
            if(prevColor){
                colorFr[prevColor]--;
                if(colorFr[prevColor] == 0){
                    colorFr.erase(prevColor);
                }
            }

            // Update ball's color
            ballColor[q[0]] = q[1];
            // Increment frequency of color
            colorFr[q[1]]++;

            // Adding count of active colors at present
            ans.push_back(min(ballColor.size(), colorFr.size()));
        }

        return ans;
    }
};