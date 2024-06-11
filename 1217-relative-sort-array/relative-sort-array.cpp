class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 11.06.24 POTD
        vector<int> ans;
        unordered_map<int,int> fr;
        set<int> st = {arr2.begin(), arr2.end()};

        for(int i=0; i<arr1.size(); i++){
            fr[arr1[i]]++;
        }

        for(int i=0; i<arr2.size(); i++){
            int f = fr[arr2[i]];
            while(f--){
                ans.push_back(arr2[i]);
            }
        }

        int sz = ans.size();

        for(int i=0; i<arr1.size(); i++){
            if(st.find(arr1[i]) == st.end())
                ans.push_back(arr1[i]);
        }

        sort(ans.begin()+sz, ans.end());

        return ans;
    }
};