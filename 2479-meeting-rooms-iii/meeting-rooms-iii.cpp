class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // 18.02.24 potd
        vector<int> ans(n,0);
        vector<long long> times(n,0);
        sort(meetings.begin(), meetings.end());

        for(int i=0; i<meetings.size(); i++){
            int start=meetings[i][0], end=meetings[i][1];
            bool f=false;
            int minIdx=-1;
            long long val=1e18;

            for(int j=0; j<n; j++){
                if(times[j]<val)
                    val=times[j], minIdx=j;
                if(times[j] <= start){
                    f=true;
                    ans[j]++;
                    times[j]=end;
                    break;
                }
            }

            if(!f){
                ans[minIdx]++;
                times[minIdx]+=(1ll*(end-start));
            }
        }

        int maxi=-1, id=-1;
        for(int i=0; i<n; i++){
            if(ans[i]>maxi) 
                maxi=ans[i], id=i;
        }

        return id;

        // MY APPROACH: FAULTY
        // queue<int> ar;  // available room
        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> br;
        // // br: busy-rooms; vector: {finish_time, start_time, room_no}
        // //  room available at the earliest will be at top
        // unordered_map<int,int> cr;  // count of room's usage
        // int i, mxUsed=0, mxUsedCount=1, mn=2, mx=0, multiple=0;
        // // mxUsed: max used room no.

        // for(i=0; i<n; i++){
        //     br.push({meetings[i][1], meetings[i][0], i});
        //     cr[i]++;

        //     if(i==meetings.size())  
        //         break;
        // }

        // while(i<meetings.size()){
        //     auto t = br.top();
        //     br.pop();

        //     int rn = t[2];
        //     br.push({meetings[i][1]-meetings[i][0]+t[1], t[1], rn});
        //     cr[rn]++;
        //     i++;
        // }

        // for(int r=0; r<n; r++){
        //     if(cr[r]>mx){
        //         mx = cr[r];
        //         multiple=0;
        //     } else if(cr[r]==mx){
        //         multiple=1;
        //     }

        //     mn = min(mn, cr[r]);
        // }

        // return multiple==1 ? mn : mx;
    }
};