class Solution {
public:

    int shortestPathLength(vector<vector<int>>& graph) {
        // 17.09.23 potd
    
        // A structure to represent the current state.
        struct State {
            int mask, node, dist;
        };

        // Getting the no. of nodes in the graph
        int n = graph.size();

        // Calculating a bitmask for all nodes visited (all bits are set to 1)
        int all_visited = (1<<n) - 1;

        // Creating a queue for BFS traversal
        queue<State> q;

        // Creating a set to track visited states
        unordered_set<int> visited;

        // Initializing the queue and visited set with all possible starting points
        for(int i=0; i<n; i++){
            // Start from each node individually
            q.push({1<<i, i, 0});

            // Use a unique hash value for each state 
            visited.insert((1<<i) * 16 + i);
        }    

        // Starting BFS traversal
        while(!q.empty()){
            State cur = q.front();  q.pop();

            // If all nodes have been visited, return the current distance
            if(cur.mask == all_visited){
                return cur.dist;
            }

            // Exploring neighbors of the current node
            for(int neighbor: graph[cur.node]){
                int new_mask = cur.mask | (1<<neighbor);
                int hash_val = new_mask * 16 + neighbor;
                
                // If the new state has no been visited, add it to the queue and mark it as visited
                if(visited.find(hash_val) == visited.end()){
                    visited.insert(hash_val);
                    q.push({new_mask, neighbor, cur.dist + 1});
                }
            }
        }

        // If no path that visits all nodes is found, return -1
        return -1;
    }

};