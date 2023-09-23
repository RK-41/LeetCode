class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // 23.09.23 potd
        // Approach: DP

        // Key Data Structures:
        //  dp: a dictionary that remembers the longesst chain length we can achieve for each word
        // max_chain: an integer variable to store the resultant chain length
        unordered_map<string,int> dp;
        int max_chain = 0;

        // Sorting the words by length - help in DP
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size()<b.size();
        });

        // Iterating over each word in the sorted 'words' vector
        for(const auto& word: words){

            // Initializing chain length for the current word with 1 as,
            //  at a minimum, a word can form a chain with itself
            dp[word] = 1;

            // Generating Previous Words: Iterating through all possible words that
            //  can be formed by removing one character from the current word.
            for(int i=0; i<word.size(); ++i){
                string prev_word = word.substr(0,i) + word.substr(i+1);

                // Updating Chain Length: If the previous word exixts in the 'dp' map
                //  ie, it's a word from the input list, it updates the chain length
                //  for the current word
                if(dp.find(prev_word) != dp.end()){
                    dp[word] = max(dp[word], dp[prev_word]+1);
                }
            }
            // Finding Maximum Chain Length: Keeping track of the max chain length 
            //  encountered so far in the variable 'max_chain'
            max_chain = max(max_chain, dp[word]);
        }

        // Returning Maximum Chain Length
        return max_chain;
    }
};