class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // 26.07.24 potd
        // Algo: Floyd-Warshall
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }

        // Distance bt nodes which are connected with temporary dist bt then
        for(const auto& e: edges){
            int nd1 = e[0], nd2 = e[1], d = e[2];
            dist[nd1][nd2] = d;
            dist[nd2][nd1] = d;
        }

        for(int middle=0; middle<n; middle++){
            for(int source=0; source<n; source++){
                for(int dest=0; dest<n; dest++){
                    if(dist[source][middle] < INT_MAX && dist[middle][dest] < INT_MAX){
                        dist[source][dest] = min(dist[source][dest], dist[source][middle] + dist[middle][dest]);
                    }
                }
            }
        }

        int mn = n, ans = -1;

        for(int source=0; source<n; source++){
            int srcCnt = 0;
            for(int dest=0; dest<n; dest++){
                if(dist[source][dest] <= distanceThreshold)
                    ++srcCnt;
            }
            if(srcCnt <= mn){
                mn = srcCnt;
                ans = source;
            }
        }

        return ans;
    }
};