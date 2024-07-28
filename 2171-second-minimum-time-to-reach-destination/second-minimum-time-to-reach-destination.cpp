inline const auto optimize = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // 28.97.24 potd
        vector<vector<int>> graph(n);

        for(const auto& e: edges){
            graph[e[0]-1].push_back(e[1]-1);
            graph[e[1]-1].push_back(e[0]-1);
        }

        deque<int> dq;
        vector<char> seen(n*2);
        dq.push_front(0);
        seen[0] = true;
        int mxLen = numeric_limits<int>::max();
        int wave = 0;
        bool odd = true;

        while(!dq.empty()){
            const int thisRound = dq.size();
            odd = !odd;

            for(int i=0; i<thisRound; i++){
                auto pos = dq.front();
                dq.pop_front();

                if(pos == n-1){
                    if(mxLen == numeric_limits<int>::max()){
                        mxLen = wave + 2;
                        continue;
                    } else {
                        mxLen = min(mxLen, wave);
                        return howLong(mxLen, time, change);
                    }
                }

                for(const auto next: graph[pos]){
                    if(seen[next*2 + !odd])
                        continue;
                    
                    seen[next*2 + !odd] = true;
                    dq.push_back(next);
                }
            }

            wave++;

            if(mxLen < wave){
                break;
            }
        }

        return howLong(mxLen, time, change);
    }

private:
    static constexpr int howLong(int needed, int time, int change){
        int ans = 0;
        for(int i=0; i<needed; i++){
            int turn = ans/change;
            if((turn%2) != 0){
                ans += change - (ans % change);
            }

            ans += time;
        }

        return ans;
    }
};