class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 21.05.24 POTD
        vector<vector<int>> subsets = {{}};
        queue<vector<int>> q;
        int n = nums.size();

        for(int a: nums){
            subsets.push_back({a});
        }        

        int i=0;
        while(i<n){
            int sz = q.size();

            while(sz--){
                auto f = q.front();
                q.pop();
                q.push(f);

                f.push_back(nums[i]);
                q.push(f);

                subsets.push_back(f);
            }
            q.push({nums[i]});
            i++;
        }
        
        return subsets;
    }
};

/*
Visualizing subset creation as nums array is iterated from start to end:

a1

a2
a1,a2

a3
a1,a3
a2,a3
a1,a2,a3

a4
a1,a3,a4
a2,a3,a4
a1,a2,a3,a4


*/