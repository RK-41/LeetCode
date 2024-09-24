class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // 24.09.24 potd
        int ans=0;
        unordered_map<string,int> prefixMap;

        for(int a: arr1){
            string s = to_string(a), prefix;

            for(char c: s){
                prefix += c;
                prefixMap[prefix]++;
            }
        }

        for(int a: arr2){
            string s = to_string(a), prefix;

            for(char c: s){
                prefix += c;
                if(prefixMap.count(prefix))
                    ans = max(ans, static_cast<int>(prefix.length()));
            }
        }

        return ans;
    }
};