class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // 24.07.24
        vector<int> updatedNums, ans;
        unordered_map<int,int> um;
        unordered_map<int,vector<int>> newMapping;

        for(int i=0; i<mapping.size(); i++){
            um[i] = mapping[i];
        }

        for(auto n: nums){
            int x = n, y = 0, p = 1;
            
            if(n == 0){
                y = um[n];
            }

            while(x>0){
                int d = x%10;
                y += um[d]*p;
                p *= 10;
                x /= 10;
            }
            newMapping[y].push_back(n);
            updatedNums.push_back(y);
        }

        sort(updatedNums.begin(),updatedNums.end());

        ans = newMapping[updatedNums[0]];
        for(int i=1; i<updatedNums.size(); i++){
            if(updatedNums[i] == updatedNums[i-1])
                continue;

            for(auto n: newMapping[updatedNums[i]]){
                ans.push_back(n);
            }
        }

        return ans;
    }
};