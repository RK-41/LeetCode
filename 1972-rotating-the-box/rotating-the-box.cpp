class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // 23.11.24 POTD
        int m = box.size();
        if(m == 0) return vector<vector<char>>();
        int n = box[0].size();
        
        // Create rotated matrix (n x m)
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        // Process each row of original box
        for(int j = 0; j < m; j++) {
            int lastObs = n;
            int cnt = 0;
            map<int,int> spo; // stones per obstacle
            
            // Scan from right to left
            for(int i = n-1; i >= 0; i--) {
                if(box[j][i] == '#') {
                    cnt++;
                } else if(box[j][i] == '*') {
                    spo[lastObs] = cnt;
                    cnt = 0;
                    lastObs = i;
                }
            }
            // Stones before first obstacle
            spo[lastObs] = cnt;
            
            // Place stones and obstacles
            for(auto s: spo) {
                int obs = s.first;
                int stones = s.second;
                
                // Place obstacle
                if(obs < n && obs >= 0) {
                    if(box[j][obs] == '*') {
                        ans[obs][j] = '*';
                    }
                }
                    
                // Place stones
                int pos = obs - 1;
                while(stones > 0 && pos >= 0) {
                    ans[pos][j] = '#';
                    pos--;
                    stones--;
                }
            }
        }
        
        // Vertical reverse
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m/2; j++) {
                swap(ans[i][j], ans[i][m-1-j]);
            }
        }
        
        return ans;
    }
};