class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // 16.09.23 potd

        int rows = heights.size(), cols = heights[0].size();

        // 'dist' is 2D vector to store the min effort needed to reach each cell.
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        
        // 'minHeap' is a priority queue (min heap) of tuples, each representing the
        //      effort, row, index, and column index of a cell.
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
        minHeap.emplace(0,0,0);

        // The starting cell (0,0) is inserted into the heap with an effort of 0.
        dist[0][0] = 0;

        // 'directions' defines four possible directions to move: right, left,
        //      down and up.
        int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        // DIJKSTRA'S ALGORITHM:
        //  The program uses Dijkstra's algorithm to explore the grid while updating
        //      the minimum effort to reach each cell.
        //  It continues until all cells are visited or until the bottom-right cell is reached.
        //  For each cell, it explores neighboring cells and calculates the effort to reach them,
        //      updating the minimum effort if needed.
        while(!minHeap.empty()){
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            if(effort > dist[x][y]) continue;

            if(x == rows-1 && y == cols-1)  return effort;

            for(auto& dir: directions){
                // Neighbor Exploration and Effort Updata:
                //  For each neighboring cell, it calculates the new effort required
                //      to reach the cell.
                //  If the new effort is less than the previously calculated effort for 
                //      that cell, it updates the effort and adds the cell to the min heap
                //      for further exploration
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >= 0 && nx < rows && ny >= 0 && ny < cols){
                    int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));

                    if(new_effort < dist[nx][ny]){
                        dist[nx][ny] = new_effort;
                        minHeap.emplace(new_effort, nx, ny);
                    }
                }
            }
        }

        // If the bottom-right cell is not reached (i.e., there's no valid path),
        //  the function returns -1;
        return -1;
    }
};