class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 10.03.24 POTD
        vector<int> ans;
        set<int> st;

        for(auto n: nums1){
            if(st.find(n) == st.end())
                st.insert(n);
        }

        for(auto n: nums2){
            if(st.find(n) != st.end()){
                ans.push_back(n);
                st.erase(n);
            }
        }

        return ans;
    }
};