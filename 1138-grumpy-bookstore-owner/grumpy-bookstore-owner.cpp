class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 21.06.24 potd
        int intlSatisf = 0, maxExtraSatisf = 9, currWindowSatisf = 0;

        for(int i=0; i<customers.size(); i++){
            if(grumpy[i] == 0){
                intlSatisf += customers[i];
            } else if(i < minutes){
                currWindowSatisf += customers[i];
            }
        }

        maxExtraSatisf = currWindowSatisf;

        for(int i=minutes; i<customers.size(); i++){
            currWindowSatisf += customers[i] * grumpy[i];
            currWindowSatisf -= customers[i-minutes] * grumpy[i-minutes];
            maxExtraSatisf = max(maxExtraSatisf, currWindowSatisf);
        }

        return intlSatisf + maxExtraSatisf;
    }
};