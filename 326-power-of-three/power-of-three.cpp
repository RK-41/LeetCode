class Solution {
public:
    bool isPowerOfThree(int n) {
        // 13.08.25 (POTD)
        if(n==1 || n==3)    return true;
        if(n<3 || n%3!=0)     return false;

        return isPowerOfThree(n/3);
    }
};