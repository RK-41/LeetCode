class Solution {
public:
    bool doesAliceWin(string s) {
        // 21.07.24
        bool turn = false;

        while(s.size()){
            turn = !turn;
            int n=s.size(), count=0, idx=-1, i=0;

            while(i<n){
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    count++;

                if(turn && count%2 == 1){
                    idx = i;
                } else if(!turn && count%2 == 0){
                    idx = i;
                }

                i++;
            }

            if(idx == -1){
                turn = !turn;
                break;
            }

            s = s.substr(idx+1);
        }

        return turn;
    }
};