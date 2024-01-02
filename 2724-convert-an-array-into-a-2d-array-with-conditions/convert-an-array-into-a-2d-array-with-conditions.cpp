class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // 02.01.24 POTD
        vector<vector<int>> ans;
        unordered_map<int,int> fr;
        vector<int> v;

        for(int i=0; i<nums.size(); i++){
            if(fr.find(nums[i])==fr.end()){
                v.push_back(nums[i]);
            }
            fr[nums[i]]++;
        }

        ans.push_back(v);
        if(v.size()==nums.size())
            return ans;

        while(true){
            v.clear();
            for(auto p: fr){
                if(p.second>1){
                    v.push_back(p.first);
                    fr[p.first]--;
                }
            }
            if(v.size()==0)
                break;
            ans.push_back(v);
        }

        return ans;
    }
};