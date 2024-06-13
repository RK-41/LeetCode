class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // 13.06.24 POTD
        int ans=0, n=seats.size();
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        for(int i=0; i<n; i++){
            ans += abs(seats[i] - students[i]);
        }

        return ans;
    }
};