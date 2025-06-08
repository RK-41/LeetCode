class Solution {
    public List<Integer> lexicalOrder(int n) {
        // 08.06.25 potd
        List<Integer> ans = new ArrayList<>();
        int cnt = 1;

        for(int i=0; i<n; i++){
            ans.add(cnt);
            if(cnt * 10 <= n){
                cnt *= 10;  // move to next lexicographical level
            } else {
                if(cnt >= n)
                    cnt /= 10;  // backtrack if needed
                cnt++;

                while(cnt % 10 == 0){
                    cnt /= 10;  // skip trailing zeros
                }
            }
        }

        return ans;
    }
}