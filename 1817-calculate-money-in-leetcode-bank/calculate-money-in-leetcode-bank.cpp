class Solution {
public:
    int totalMoney(int n) {
        // 06.12.23 POTD

        int money=0, mon=1, curr=1;
        for(int i=1; i<=n; i++){
            money += curr;
            
            if(i%7==0){
                curr = mon+1;
                mon++;
            } else {
                curr++;
            }
        }

        return money;
    }
};