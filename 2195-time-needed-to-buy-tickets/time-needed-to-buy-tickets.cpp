class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // 09.04.24
        int ans=0;
        queue<int> q;

        for(int i=0; i<tickets.size(); i++){
            q.push(i);
        }

        while(q.size()){
            int i=q.front();
            q.pop();

            ans++;
            tickets[i]--;

            if(tickets[i]>0)
                q.push(i);

            if(i==k && tickets[i]==0)
                break;
        }

        return ans;
    }
};