class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 15.09.23 potd

        int n=points.size();
        vector<bool> vis(n, false);
        unordered_map<int,int> heap_dict;


        // Initializing all distanced to ininity
        for(int i=0; i<n; ++i){
            heap_dict[i] = INT_MAX;
        }
        
        // Start node
        heap_dict[0] = 0;

        // Priority Queue Initialization:
        //  'cmp' is a lambda function used to define the comparison function for the priority queue.
        //  It ensures that the pair with the smallest distance ('left.first') comes at
        //      the top of the queue.
        auto cmp = [](pair<int,int> left, pair<int,int> right){
            return left.first > right.first;
        };

        // 'min_heap' is a priority queue of pairs, where each pair contains the distance and the node index.
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)>min_heap(cmp);
        
        // Initially, the start node(index 0) with a distance of 0 is pushed onto the 'min_heap'.
        min_heap.push({0,0});

        // Minimum Spanning Tree Construction:
        int mst_weight = 0;

        // The loop continues until the 'min_heap' is empty.
        // It extracts the node 'u' with the smallest distance from the heap.
        // IF 'u' has already been visited or the distance in 'min_heap' is smaller than 'w',
        //      it is skipped (to avoid cycles in the MST).
        // Otherwise, 'u' is marked as visited, and its distance ('w') is added to the MST weight.
        // For each unvisited node 'v', it calculated the Manhattan distance between 'u' and 'v' 
        //      using the 'manhattan_dist' function.
        // If this new distance is smaller that the current distance stored in 'heap_dict' for node 'v',
        //      the new distance is updated in 'heap_dict', and the pair '(new_distance, v)' is
        //      pushed onto the 'min_heap'.
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

        // Finally, the function returns the total weight of the MST.
        return mst_weight;
    }

    // The 'manhattan_dist' function calculates the Manhattan distance b/w tow points 'p1' and 'p2'.
    // Manhattan distance is the sum of the absolute differences of their x and y coordinates.
    int manhattan_dist(vector<int>& p1, vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};