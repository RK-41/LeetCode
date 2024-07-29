class Solution {
public:
    int numTeams(vector<int>& rating) {
        // 29.07.24 POTD
        int ans=0, n=rating.size();

        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                bool ascending = false;;
                if(rating[i] < rating[j])
                    ascending = true;

                for(int k=j+1; k<n; k++){
                    if(ascending && rating[j] < rating[k])
                        ans++;
                    else if(!ascending && rating[j] > rating[k])
                        ans++;
                }
            }
        }

        return ans;
    }
};