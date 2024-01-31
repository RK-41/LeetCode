class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 31.01.24 potd
        vector<int> ans(temperatures.size(), 0);
        deque<int> dq;

        for(int i=temperatures.size()-1; i>=0; i--){
            if(dq.empty()){
                dq.push_front(i);
                ans[i]=0;
            } else {
                while(dq.size() && temperatures[i]>=temperatures[dq.front()]){
                    dq.pop_front();
                }

                if(dq.empty()){
                    ans[i]=0;
                } else {
                    ans[i]=dq.front()-i;
                }

                dq.push_front(i);
            }
        }

        return ans;
    }
};