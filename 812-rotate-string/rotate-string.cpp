class Solution {
public:
    bool rotateString(string s, string goal) {
        // 03.11.24 POTD
        vector<int> firstCharPos;

        for(int i=0; i<s.size(); i++){
            if(s[i] == goal[0])
                firstCharPos.push_back(i);
        }

        for(auto i: firstCharPos){
            string t = s.substr(i) + s.substr(0,i);
            if(t == goal)   
                return true;
        }

        return false;
    }
};