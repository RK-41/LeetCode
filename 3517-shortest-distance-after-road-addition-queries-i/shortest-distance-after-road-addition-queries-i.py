class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        # 27.11.24 potd
        adj = [[i+1] for i in range(n)]

        def shortestPath():
            q = deque()
            q.append((0,0)) # node, len
            visit = set()
            visit.add((0,0))

            while q:
                cur, len = q.popleft()
                if cur == n-1:
                    return len
                
                for ngb in adj[cur]:
                    if ngb not in visit:
                        q.append((ngb, len+1))
                        visit.add(ngb)
        
        ans = []
        for src, dist in queries:
            adj[src].append(dist)
            ans.append(shortestPath())

        return ans