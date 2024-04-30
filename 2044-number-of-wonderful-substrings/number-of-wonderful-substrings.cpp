class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // 30.04.24 potd
        vector<long long> count(1024,0);
        long long ans=0;
        int prefixXor=0;
        count[prefixXor]=1;

        for(char ch: word){
            int idx = ch-'a';
            prefixXor ^= 1 << idx;
            ans += count[prefixXor];

            for(int i=0; i<10; i++){
                ans += count[prefixXor ^ (1<<i)];
            }

            count[prefixXor]++;
        }

        return ans;
    }
};