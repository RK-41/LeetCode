class Solution {
public:
    bool equalFrequency(string word) {

        vector<int> fr(26,0);

        // mapping char to their fr
        for(auto w: word)
            fr[w-'a']++;

        // checking for every possible char if its removal can make fr equal
        for(auto w: word){

            // decrementing fr of curr char
            fr[w-'a']--;

            set<int> st;
            int flg=1;
            for(int i=0; i<26; i++){
                if(fr[i]==0)    continue;

                if(fr[i]>0)
                    st.insert(fr[i]);

                // if st.size()>1 this means deleting an instance of curr char doesn't make the fr of all char equal
                // that's why st contains two diff fr
                if(st.size()>1){
                    flg=0;
                    break;
                } 
            }

            if(flg) return true;

            // incrementing fr of curr char for following loops
            fr[w-'a']++;
        }

        return false;
    }
};