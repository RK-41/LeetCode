class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // 31.10.24 potd
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int m=robot.size(), n=factory.size();
        vector<vector<long long>> dp(m+1, vector<long long>(n+1));

        // Base case: if no factories are avaibalbe, dist is infinity
        for(int i=0; i<m; i++){
            dp[i][n] = LLONG_MAX;
        }

        // Process each factory right to left
        for(int j=n-1; j>=0; j--){
            // Cumulative dist from curr factory to robots
            long long prefix = 0;
            // Storing pairs of {robot idx, min dist}
            deque<pair<int, long long>> qq;
            // Init with base case
            qq.push_back({m,0});

            // Process each robot from right to left
            for(int i=m-1; i>=0; i--){
                // Add dist form curr robot to curr factory
                prefix += abs(robot[i] - factory[j][0]);

                // Remove entries that exceed factory capacity
                while(!qq.empty() && qq.front().first > i + factory[j][1]){
                    qq.pop_front();
                }

                // Maintain monotonic property of deque
                while(!qq.empty() && qq.back().second >= dp[i][j+1] - prefix){
                    qq.pop_back();
                }

                // Add curr state to deque
                qq.push_back({i, dp[i][j+1] - prefix});
                // Calc minimum dist for curr state
                dp[i][j] = qq.front().second + prefix;
            }
        }

        // Return min total dist starting from first robot to first factory
        return dp[0][0];
    }
};