class Solution {
public:
    int reverseBits(int n) {
        // 16.02.26 PoTd
        int ans = 0;
        string s = bitset<32>(n).to_string();
        reverse(s.begin(), s.end());
        ans = stoi(s, nullptr, 2);

        return ans;
    }
};