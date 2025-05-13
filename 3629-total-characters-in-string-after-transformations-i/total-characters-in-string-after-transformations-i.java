class Solution {
    // 13.05.25 potd
    private static final int mod = 1000000007;
    private int modAdd(int a, int b){
        a %= mod;
        b %= mod;

        return ((a+b) % mod + mod) % mod;
    }
    public int lengthAfterTransformations(String s, int t) {
        int ans = 0;
        int[] nums = new int[26];
        for(char ch: s.toCharArray())   nums[ch-'a']++;

        while(t-- > 0){
            int[] curr = new int[26];
            for(int j=0; j<26; j++){
                if(j == 25 && nums[j] > 0){
                    curr[0] = modAdd(curr[0], nums[j]);
                    curr[1] = modAdd(curr[1], nums[j]);
                } else {
                    if(j < 25) curr[j+1] = modAdd(curr[j+1], nums[j]);
                }
            }

            nums = curr;
        }

        for(int i: nums)    ans = modAdd(ans, i);

        return ans;
    }
}