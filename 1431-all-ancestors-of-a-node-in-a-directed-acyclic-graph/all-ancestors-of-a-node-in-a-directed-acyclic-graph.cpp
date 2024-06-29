class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // 29.06.24 potd
        vector<vector<int>> ans(n), graph(n);

        for(const auto& e: edges){
            graph[e[0]].push_back(e[1]);
        }

        for(int i=0; i<n; i++){
            vector<bool> vis(n, false);
            dfs(graph, i, i, ans, vis);
        }

        for(int i=0; i<n; i++){
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& ans, vector<bool>& vis){
        vis[curr] = true;

        for(int dest: graph[curr]){
            if(!vis[dest]){
                ans[dest].push_back(parent);
                dfs(graph, parent, dest, ans, vis);
            }
        }
    }
};