class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // 20.04.24 potd
        // Approach: BFS
        vector<vector<int>> ans;
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        set<pair<int,int>> vis;
        int r=land.size(), c=land[0].size();

        auto bfs = [&](int start_r, int start_c) -> vector<int>{
            queue<pair<int,int>> q;
            q.push({start_r, start_c});
            vis.insert({start_r, start_c});
            int min_r = start_r, min_c = start_c, max_r = start_r, max_c = start_c;

            while(q.size()){
                auto [cur_r, cur_c] = q.front();
                q.pop();

                for(auto [dr, dc]: dir){
                    int new_r = cur_r + dr;
                    int new_c = cur_c + dc;

                    if(new_r >= 0 && new_r < r && new_c >= 0 && new_c < c && vis.find({new_r, new_c}) == vis.end() && land[new_r][new_c] == 1){
                        vis.insert({new_r, new_c});
                        q.push({new_r, new_c});
                        min_r = min(min_r, new_r);
                        min_c = min(min_c, new_c);
                        max_r = max(max_r, new_r);
                        max_c = max(max_c, new_c);
                    }
                }
            }

            return {min_r, min_c, max_r, max_c};
        };

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(land[i][j] == 1 && vis.find({i,j}) == vis.end()){
                    vector<int> farmland = bfs(i, j);
                    ans.push_back(farmland);
                }
            }
        }

        return ans;
    }
};