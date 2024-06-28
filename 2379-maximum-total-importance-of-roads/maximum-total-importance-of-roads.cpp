class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // 28.06.24 potd
        vector<int> deg(n), cities(n);
        long long totalImp = 0;

        for(const auto& road: roads){
            deg[road[0]]++;
            deg[road[1]]++;
        }

        for(int i=0; i<n; i++){
            cities[i] = i;
        }

        sort(cities.begin(), cities.end(), [&](int a, int b){
            return deg[a] > deg[b];
        });

        // Assigning values to cities starting from the highest degree
        for(int i=0; i<n; i++){
            totalImp += (long long)(n-i) * deg[cities[i]];
        }

        return totalImp;
    }
};