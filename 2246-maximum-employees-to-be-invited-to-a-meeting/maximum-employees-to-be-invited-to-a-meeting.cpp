class Solution {
public:
    int maximumInvitations(vector<int>& fav) {
        // 26.01.25 potd
        int n = fav.size(), maxCycle = 0, pairChains = 0;
        queue<int> q;   // Handles employees not in cycles
        vector<int> vis(n); // Tracks processed employees
        vector<int> inDeg(n), chainLen(n);  // inDeg: fav counts; chainLen: longest chain to each

        // Step 1: Calc how many people favor each employee
        for(int x: fav) inDeg[x]++;

        // Step 2: Start with employees no one favorites (chain starters)
        for(int i=0; i<n; i++)
            if(!inDeg[i])   q.push(i);

        // Step 3: Process chain starters to find longest chains
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = true;  // Marks as processed
            int nbr = fav[u];
            chainLen[nbr] = max(chainLen[nbr], chainLen[u] + 1);    // Update chain len
            if(--inDeg[nbr] == 0)
                q.push(nbr);    // Process when all dependents are handled
        }

        // Step 4: Check remaining employees for cycles
        for(int i=0; i<n; i++){
            if(vis[i])  continue;   // Already processed in chains

            int cycLen = 0, u = i;

            // Measure cycle length
            while(!vis[u]){
                vis[u] = true;
                u = fav[u];
                cycLen++;
            }

            // Handle mutual pairs (cycles of 2) with their chains
            if(cycLen == 2)
                pairChains += 2 + chainLen[i] + chainLen[fav[i]];
            // Track longest non-pair cycle
            else
                maxCycle = max(maxCycle, cycLen);
        }

        // Choose best option: largest cycle or mutual pairs with chains
        return max(maxCycle, pairChains);
    }
};