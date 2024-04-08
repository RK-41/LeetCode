class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // 08.04.24 potd
        vector<int> cnt(2, 0);
        for(int s: students){
            cnt[s]++;
        } 

        int remaining = sandwiches.size();

        for(int s: sandwiches){
            if(cnt[s] == 0 || remaining == 0)
                break;
            
            cnt[s]--;
            remaining--;
        }

        return remaining;
    }
};