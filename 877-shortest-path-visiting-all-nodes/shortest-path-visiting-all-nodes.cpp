class Solution {
public:
    struct State {
        int mask, node, dist;
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        // 17.09.23 potd
        
        int n = graph.size();
        int all_visited = (1<<n) - 1;
        queue<State> q;
        unordered_set<int> visited;

        for(int i=0; i<n; i++){
            q.push({1<<i, i, 0});
            visited.insert((1<<i) * 16 + i);
        }    

        while(!q.empty()){
            State cur = q.front();  q.pop();

            if(cur.mask == all_visited){
                return cur.dist;
            }

            for(int neighbor: graph[cur.node]){
                int new_mask = cur.mask | (1<<neighbor);
                int hash_val = new_mask * 16 + neighbor;
                
                if(visited.find(hash_val) == visited.end()){
                    visited.insert(hash_val);
                    q.push({new_mask, neighbor, cur.dist + 1});
                }
            }
        }

        return -1;
    }
};