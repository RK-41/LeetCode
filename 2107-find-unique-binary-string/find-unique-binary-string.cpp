class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // 10.09.23 (potd)
        
        set<string> st(nums.begin(), nums.end());
        queue<string> q;
        q.push(nums[0]);

        while(q.size()){
            if(st.find(q.front()) == st.end())
                break;

            q.push(q.front().substr(1)+"0");
            q.push(q.front().substr(1)+"1");
            
            q.pop();
        }
        return q.front();
    }
};