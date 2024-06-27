class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // 27.06.24 POTD
        unordered_set<int> st;

        for(auto p: edges){
            if(st.find(p[0]) != st.end())
                return p[0];

            if(st.find(p[1]) != st.end())
                return p[1];

            st.insert(p[0]);
            st.insert(p[1]);
        }

        return 0;
    }
};