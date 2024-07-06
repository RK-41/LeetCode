class Solution {
public:
    int passThePillow(int n, int time) {
        // 06.07.24 POTD
        int qt = time/(n-1);
        int md = time%(n-1);

        if(qt%2 == 0)
            return md+1;

        return n-md;
    }
};