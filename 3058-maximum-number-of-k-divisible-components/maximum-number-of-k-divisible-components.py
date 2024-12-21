class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], vals: List[int], k: int) -> int:
        # 21.12.24 potd
        from collections import deque, defaultdict

        if n < 2:
            return 1

        graph = defaultdict(list)
        degree = [0]*n

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
            degree[a] += 1
            degree[b] += 1

        nodeVals = vals[:]
        leafQ = deque([i for i in range(n) if degree[i] == 1])
        compCnt = 0

        while leafQ:
            curr = leafQ.popleft()
            degree[curr] -= 1
            carry = 0

            if nodeVals[curr]%k == 0:
                compCnt += 1
            else:
                carry = nodeVals[curr]

            for nbr in graph[curr]:
                if degree[nbr] == 0:
                    continue
                degree[nbr] -= 1
                nodeVals[nbr] += carry
                
                if degree[nbr] == 1:
                    leafQ.append(nbr)

        return compCnt