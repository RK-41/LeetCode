class Solution {
public:
    vector<vector<string>> partition(string s) {
        // 22.05.24 potd
        vector<vector<string>> ans;
        vector<string> path;
        backtrack(s, 0, path, ans);

        return ans;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& ans){
        // If end of string is reached, add the curr partition to the ans
        if(start == s.length()){
            ans.push_back(path);
            return;
        }

        // Exploring all possible partitions
        for(int end=start+1; end<=s.length(); ++end){
            // If the curr substr is a palindrome, add it to the curr path
            if(isPalindrome(s, start, end-1)){
                path.push_back(s.substr(start, end-start));

                // Recur to find other partitions
                backtrack(s, end, path, ans);

                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--])
                return false;
        }

        return true;
    }
};