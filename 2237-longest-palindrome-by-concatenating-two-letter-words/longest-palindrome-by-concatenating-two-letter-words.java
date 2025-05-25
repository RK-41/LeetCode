class Solution {
    public int longestPalindrome(String[] words) {
        // 25.05.25 
        int[][] mp = new int[26][26];
        int count = 0, middle = 0;

        for(String s: words){
            int x = s.charAt(0) - 'a', y = s.charAt(1) - 'a';
            if(mp[y][x] > 0){
                mp[y][x]--;
                count += 4;

                if(x==y)
                    middle--;
            } else {
                mp[x][y]++;
                if(x==y)
                    middle++;
            }
        }

        if(middle > 0)
            count += 2;
        
        return count;
    }
}