class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // 09.07.24 POTD
        double ans=0;
        long long int time = customers[0][0] + customers[0][1], cookingTime = customers[0][1], waitingTime = 0, n = customers.size();

        for(int i=1; i<n; i++){
            cookingTime += customers[i][1];

            if(time > customers[i][0]){
                waitingTime += time - customers[i][0];
                time += customers[i][1];
            } else {
                time = customers[i][0] + customers[i][1];
            }
        }

        ans = (double)(cookingTime + waitingTime)/n;

        return ans;
    }
};