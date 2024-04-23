class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // 23.04.24 potd
        if(n==1)    return {0};

        vector<int> ans;
        vector<list<int>> adj(n);
        vector<int> deg(n,0);
        queue<int> leaves;

        for(auto &e: edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        for(int i=0; i<n; ++i){
            if(deg[i]==1)
                leaves.push(i);
        }

        int remNodes = n;
        while(remNodes > 2){
            int leavesCnt = leaves.size();
            remNodes -= leavesCnt;
            for(int i=0; i<leavesCnt; ++i){
                int leaf = leaves.front();
                leaves.pop();

                for(int neigh: adj[leaf]){
                    if(--deg[neigh] == 1){
                        leaves.push(neigh);
                    }
                }
            }
        }

        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }

        return ans;
    }
};