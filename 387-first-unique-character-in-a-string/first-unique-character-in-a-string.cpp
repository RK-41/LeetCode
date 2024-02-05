class Solution {
public:
    int firstUniqChar(string s) {
        // 05.02.24 POTD
        int n=s.size();
        int ans=n-1; 
        unordered_map<char,int> um;

        for(int i=n-1; i>=0; i--){
            if(um[s[i]]==0){
                ans=i;
            }
            um[s[i]]++;
        }

        if(um[s[ans]]>1){
            for(int i=0; i<n; i++){
                if(um[s[i]]==1)
                    return i;
            }
        }
        
        return um[s[ans]]==1 ? ans : -1;
    }
};