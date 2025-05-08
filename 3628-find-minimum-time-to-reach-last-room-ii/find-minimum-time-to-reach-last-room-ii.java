class Solution {
    public int minTimeToReach(int[][] moveTime) {
        // 08.05.25 potd
        int n = moveTime.length, m = moveTime[0].length;
        int INF = Integer.MAX_VALUE;
        int[][] dp = new int[n][m];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], INF);
        }

        PriorityQueue<int[]> minh = new PriorityQueue<>(Comparator.comparing(a -> a[0]));
        minh.add(new int[]{0, 0, 0});
        moveTime[0][0] = 0;

        int[][] dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        while(!minh.isEmpty()){
            int[] curr = minh.poll();
            int currTime = curr[0];
            int currRow = curr[1];
            int currCol = curr[2];

            if(currTime >= dp[currRow][currCol])    continue;

            if(currRow == n-1 && currCol == m-1)    return currTime;
            dp[currRow][currCol] = currTime;

            for(int[] d: dir){
                int nextRow = currRow + d[0];
                int nextCol = currCol + d[1];

                if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && dp[nextRow][nextCol] == INF){
                    int cost = (currRow + currCol) % 2 + 1;
                    int start = Math.max(moveTime[nextRow][nextCol], currTime);
                    int nextTime = start + cost;

                    minh.add(new int[]{nextTime, nextRow, nextCol});
                }
            }
        }

        return -1;
    }
}