class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        # 30.11.24 potd
        # Step 1: Build the graph
        graph = defaultdict(deque)
        inDeg = defaultdict(int)
        outDeg = defaultdict(int)

        for s, e in pairs:
            graph[s].append(e)
            outDeg[s] += 1
            inDeg[e] += 1

        # Step 2: Find the starting node for the Eulerian path
        startNode = pairs[0][0]
        for node in graph:
            if outDeg[node] > inDeg[node]:
                startNode = node
                break
        
        # Step 3: Hierholzer's algo to find the Eulerian path
        stack = [startNode]
        ans = []

        while stack:
            while graph[stack[-1]]:
                nextNode = graph[stack[-1]].popleft()
                stack.append(nextNode)
            
            ans.append(stack.pop())

        # Step 4: Format the ans in reverse order
        ans.reverse()

        return [[ans[i], ans[i+1]] for i in range(len(ans) - 1)]