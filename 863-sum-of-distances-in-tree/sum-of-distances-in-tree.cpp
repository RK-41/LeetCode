class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> ans;

    void dfs(int node, int parent){
        for(int child: graph[node]){
            if(child != parent){
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent){
        for(int child: graph[node]){
            if(child != parent){
                ans[child] = ans[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // 28.04.24 potd
        graph.clear();
        count = vector<int>(n,1);
        ans = vector<int>(n,0);

        for(auto &ed: edges){
            int u = ed[0], v = ed[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0,-1);
        dfs2(0,-1);

        return ans;
    }
};