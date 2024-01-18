class Solution {
public:
    unordered_map<int,int> ways;
    int climbStairs(int n) {
        // 18.01.24 POTD
        if(n==1 || n==2)
            return n;

        if(ways.find(n-1)==ways.end())
            ways[n-1] = climbStairs(n-1);

        if(ways.find(n-2)==ways.end())
            ways[n-2] = climbStairs(n-2);

        return ways[n-1]+ways[n-2];
    }
};