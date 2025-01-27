class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        # 27.01.25 potd
        adj = [[] for _ in range(numCourses)]
        preReq = [0] * numCourses   # Bitmask for prerequisites
        inDeg = [0] * numCourses

        # Build graph and initialize direct prerequisites
        for a, b in prerequisites:
            adj[a].append(b)
            preReq[b] |= 1 << a # Set the a-th bit for course b
            inDeg[b] += 1

        # Topological sort using Kahn's algo
        q = deque()
        for i in range(numCourses):
            if inDeg[i] == 0:
                q.append(i)
            
        while q:
            u = q.popleft()
            for v in adj[u]:
                preReq[v] |= preReq[u]  # Merge u's prereq into v's
                inDeg[v] -= 1
                if inDeg[v] == 0:
                    q.append(v)

        # Ans queries using bitmask checks
        ans = []
        for u, v in queries:
            ans.append((preReq[v] & (1 << u)) != 0)

        return ans