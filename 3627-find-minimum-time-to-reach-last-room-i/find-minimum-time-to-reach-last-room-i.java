class Solution {
    public int minTimeToReach(int[][] moveTime) {
        // 07.05.25 potd
        int n = moveTime.length, m = moveTime[0].length;
        int[][] dp = new int[n][m];

        for(int[] row: dp)
            Arrays.fill(row, Integer.MAX_VALUE);
        
        PriorityQueue<int[]> minh = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
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

                if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && dp[nextRow][nextCol] == Integer.MAX_VALUE){
                    int nextTime = Math.max(moveTime[nextRow][nextCol], currTime) + 1;
                    minh.add(new int[]{nextTime, nextRow, nextCol});
                }
            }
        }

        return -1;
    }
}