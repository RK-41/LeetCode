class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // 19.07.25 (potd)
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++){
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0){
                ans.push_back(folder[i]);
            }
        }
        
        return ans;
    }
};