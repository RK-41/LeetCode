class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 14.09.23 potd
        // Approach: DFS
        
        // Step 1: Creating/populating the graph
        unordered_map<string, vector<string>> graph;

        for(auto& ticket: tickets){
            graph[ticket[0]].push_back(ticket[1]);
        }

        // Step 2: Sorting destinations in reverse lexicogrphical order(descending order).
        // Sorting in reverse order ensures that lexicographically smaller airports are visited first.
        for(auto& [_, destinations]: graph){
            sort(destinations.rbegin(), destinations.rend());
        }

        // Step 3: Defining 'dfs' function
        // It's main part of the program which takes an argument and explores
        // all possible routes starting from that airport.
        vector<string> itinerary;
        
        function<void(const string&)> dfs = [&](const string& airport){
            while(!graph[airport].empty()){
                string next = graph[airport].back();
                graph[airport].pop_back();
                dfs(next);
            }

            itinerary.push_back(airport);
        };
        // It repeatedly selects the last destination from the lsit of destinations
        // for the current airport.
        // It removes the destination from the list.
        // It recursively calls itself with the selected destination as the new
        // starting airport.
        // Finally, it adds the current airport to the 'itinerary' vector.

        // Step 4: DFS
        // Calling dfs function
        dfs("JFK");

        // Step 5: Reversing the itinerary
        // After the dfs is complete, the itinerary vector contains the airports in
        // reverse order (from destination to source).
        // To get the correct order, the program reverses the 'itinerary' vector.
        reverse(itinerary.begin(), itinerary.end());

        // Step 6: Returning result
        // The function returns the computed itinerary vector, which contains
        // the lexicographically smallest valid itinerary.
        return itinerary;

    }
};