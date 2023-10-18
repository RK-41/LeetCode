class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 18.10.23 potd

        unordered_map<int,vector<int>> graph;
        vector<int> indegree(n+1, 0);

        for(auto &relation: relations){
            // Graph Representation
            graph[relation[0]].push_back(relation[1]);
    
            // In-degree Calculation
            indegree[relation[1]]++;
        }

        // Topological Sort using BFS
        vector<int> dist = time;
        dist.insert(dist.begin(), 0);
        queue<int> q;

        for(int i=1; i<=n; i++){
            if(indegree[i] == 0)    
                q.push(i);
        }

        while(q.size()){
            int course = q.front(); q.pop();

            for(int next_course: graph[course]){
                dist[next_course] = max(dist[next_course], dist[course]+time[next_course-1]);

                indegree[next_course]--;

                if(indegree[next_course] == 0)
                    q.push(next_course);
            }
        }

        return *max_element(dist.begin(), dist.end());
    }
};