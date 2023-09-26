class Solution {
public:
    string removeDuplicateLetters(string s) {
        // 26.09.23 Potd

        // Key DS:
        //  fr: A dictionary/map to hold the frequency of each character
        //  vis: A set to track characters already in the result
        //  ans: A string to hold the final characters in the desired order
        unordered_map<char,int> fr;
        set<char> vis;
        string ans;

        // Finding Frequencies
        for(auto ch: s)
            fr[ch]++;

        // Iterating through the string
        for(auto ch: s){
            // for each char, decrease its count
            fr[ch]--;

            // If it's already visited, skip/continue
            if(vis.find(ch) != vis.end())
                continue;

            // Else, if it's not visited, add it to the result/ans.
            //  While adding, compare it with the last char in the result/ans.
            //  If the current char is smaller and the last char appears later in the
            //      string, remove the last char
            while(ans.size() and ch<ans.back() and fr[ans.back()]>0){
                vis.erase(ans.back());
                ans.pop_back();
            }

            // Append the current char and insert it in the set
            ans += ch;
            vis.insert(ch);
        }

        // Return the result/ans
        return ans;
    }
};