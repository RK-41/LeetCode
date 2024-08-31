class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // 27.08.24 potd
        // 31.08.24 (potd)
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        for(int i=0; i<n-1; i++){
            bool updated=false;
            for(int j=0; j<edges.size(); j++){
                int u=edges[j][0], v=edges[j][1];
                double prob = succProb[j];

                if(maxProb[u]*prob > maxProb[v]){
                    maxProb[v] = maxProb[u]*prob;
                    updated = true;
                }
                
                if(maxProb[v]*prob > maxProb[u]){
                    maxProb[u] = maxProb[v]*prob;
                    updated = true;
                }
            }

            if(!updated)    
                break;
        }

        return maxProb[end_node];
    }
};