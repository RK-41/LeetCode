class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # 25.11.24 potd
        target = "123450"
        start = ''.join(str(num) for row in board for num in row)

        # Neighbord map for each index in the 1D representation of the board
        neighbors = {
            0: [1,3],
            1: [0,2,4],
            2: [1,5],
            3: [0,4],
            4: [1,3,5],
            5: [2,4]
        }

        # BFS setup
        que = deque([(start,0)]) # (state, moves)
        visited = set()
        visited.add(start)

        while que:
            state, moves = que.popleft()

            # Check if we've reached the target
            if state == target:
                return moves

            # Find the index of zero
            zIdx = state.index('0')

            # Generate new states by swapping '0' with its neighbors
            for ng in neighbors[zIdx]:
                # Convert state to a list for mutation
                newState = list(state)
                # Swap '0' with the neighbor
                newState[zIdx], newState[ng] = newState[ng], newState[zIdx]
                # Convert back to string
                newStateStr = ''.join(newState)

                # If this new state hasn't been visited, add it to the queue
                if newStateStr not in visited:
                    visited.add(newStateStr)
                    que.append((newStateStr, moves+1))

        # If queue is exhausted without finding the target
        return -1