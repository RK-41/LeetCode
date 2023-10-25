class Solution {
public:
    int kthGrammar(int n, int k) {
        // 25.10.23 potd
        // Approach: Recursion
        if(n==1)   return 0;

        int len = 1<<(n-2);

        if(k <= len)    return kthGrammar(n-1, k);
        else return 1 - kthGrammar(n-1, k-len);
    }  
};

// 0
// 01
// 0110
// 01101001
// 0110100110010110