class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // 18.09.23 POTD

        // Data Structures Used
        // 'ans' vector: to store the answer of this problem.
        // 'soldiers' unordered-map: to map each row(0-indexed) to the no. of 
        //      soldiers(1's) in that row.
        // 'pq' priority-queue (min-heap): to store a pair {soldiers[i],i} ie, no. of 
        //      soldiers along with the row-number.

        vector<int> ans;
        unordered_map<int,int> soldiers;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Traversing the matrix
        for(int i=0; i<mat.size(); i++){
            // Storing no. of soldiers in each row
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==0)    break;

                soldiers[i]+=mat[i][j];
            }

            // storing the no. of soldiers in current row along with the row-number
            pq.push({soldiers[i],i});
        }

        // Retrieving top 'k' rows(pair.second) sorted wrt the no. of soldiers(pair.first)
        while(pq.size() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Returning the ans/result
        return ans;
    }
};