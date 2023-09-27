class Solution {
public:
    string decodeAtIndex(string s, int k) {
        // 27.09.23 potd
        // Approach: Reverse Traversal
        // TC: O(n)     SC: O(1)

        // Key DS:
        //  len: An integer variable to keep track of the current length of the decoded stirng
        long long len = 0;
        int i=0;

        // Forward Traversal
        //  Traversing the string from start to end, updating the length based on whether
        //      a letter or a digit is encountered.
        while(len<k){
            if(isdigit(s[i]))   len *= s[i]-'0';
            else    len++;

            i++;
        }

        // Reverse Traversal
        //  Starting from end of the string, if a digit is encountered, divide the length 'len'
        //      by the digit and update 'k' using modulo operation.
        //      If a letter is encountered and 'k' equals 0 or 'len', return the letter.
        for(int j=i-1; j>=0; j--){
            if(isdigit(s[j])){
                len /= s[j]-'0';
                k %= len;
            }
            else{
                if(k==0 || k==len){
                    return string(1, s[j]);
                }
                len--;
            }
        }

        // Default return, should never reach here given problem constraints
        return "";
    }
};