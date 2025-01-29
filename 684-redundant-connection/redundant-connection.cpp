class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 29.01.25 potd
        unordered_map<int, vector<int>> graph;

        auto isConnected = [&](int u, int v){
            unordered_set<int> vis;
            stack<int> stk;
            stk.push(u);

            while(!stk.empty()){
                int node = stk.top();
                stk.pop();

                if(vis.count(node)) 
                    continue;
                
                vis.insert(node);

                if(node == v)
                    return true;

                for(int ngr: graph[node])
                    stk.push(ngr);
            }
    
            return false;
        };


        for(const auto& edge: edges){
            int u = edge[0], v = edge[1];

            if(graph.count(u) && graph.count(v) && isConnected(u, v)){
                return edge;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};