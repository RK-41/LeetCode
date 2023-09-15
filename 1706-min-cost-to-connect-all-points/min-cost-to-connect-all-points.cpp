class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 15.09.23 potd

        int n=points.size();
        vector<bool> vis(n, false);
        unordered_map<int,int> heap_dict;


        // Initializing all distanced to to ininity
        for(int i=0; i<n; ++i){
            heap_dict[i] = INT_MAX;
        }
        
        // Start node
        heap_dict[0] = 0;

        auto cmp = [](pair<int,int> left, pair<int,int> right){
            return left.first > right.first;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>min_heap(cmp);
        min_heap.push({0,0});

        int mst_weight = 0;

        while(!min_heap.empty()){
            auto [w,u] = min_heap.top();
            min_heap.pop();

            if(vis[u] || heap_dict[u] < w)  continue;

            vis[u] = true;
            mst_weight += w;

            for(int v=0; v<n; ++v){
                if(!vis[v]){
                    int new_dist = manhattan_dist(points[u], points[v]);

                    if(new_dist < heap_dict[v]){
                        heap_dict[v] = new_dist;
                        min_heap.push({new_dist,v});
                    }
                }
            }
        }

        return mst_weight;
    }

    int manhattan_dist(vector<int>& p1, vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};