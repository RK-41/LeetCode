class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 21.04.24 potd
        // Approach: DFS
        unordered_map<int, vector<int>> graph;
        unordered_set<int> vis;

        for(const auto& e: edges){
            int u=e[0], v=e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(source, destination, graph, vis);
    }

    bool dfs(int node, int dest, unordered_map<int, vector<int>> &graph, unordered_set<int> &vis){
        if(node == dest)
            return true;

        vis.insert(node);

        for(int ng: graph[node]){
            if(vis.find(ng) == vis.end()){
                if(dfs(ng, dest, graph, vis))
                    return true;
            }
        }
        
        return false;
    }
};