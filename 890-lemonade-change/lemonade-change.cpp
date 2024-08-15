class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // 15.08.24 POTD
        int fives=0, tens=0, twenties=0;
        
        for(auto b: bills){
            if(b == 5){
                fives++;
            } else if (b == 10){
                if(fives > 0){
                    tens++;
                    fives--;
                } else {
                    return false;
                }
            } else {
                if(fives > 0 && tens > 0){
                    twenties++;
                    tens--;
                    fives--;
                } else if(fives > 2){
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};