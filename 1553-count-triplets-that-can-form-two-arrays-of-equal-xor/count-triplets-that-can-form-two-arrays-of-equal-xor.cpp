class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // 30.05.24 potd
        int ans=0;

        for(int i=0; i<arr.size(); i++){
            int val = arr[i];

            for(int k=i+1; k<arr.size(); k++){
                val ^= arr[k];

                if(val == 0){
                    ans += (k-i);
                }
            }
        }

        return ans;
    }
};