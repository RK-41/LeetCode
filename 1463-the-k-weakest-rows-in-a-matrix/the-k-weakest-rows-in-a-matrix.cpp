class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // 18.09.23 POTD

        // Data Structures Used:
        // 'ans' vector: to store the row-numbers (answer of this problem).
        // 'pq' priority-queue (min-heap): to store a pair {soldiers[i],i} ie, no. of 
        //      soldiers along with the row-number.

        vector<int> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Traversing the matrix
        for(int i=0; i<mat.size(); i++){
            // Since, the soldiers and civilians are represented by a binary value (1 & 0
            //      resprectively), the sum of elements of each row will be the no. of soldiers
            //      in that row
            // The 'accumulate()' function finds the sum of elements in the given range

            // Storing no. of soldiers in each row to 'mat[i][0]' (ie, first element of each
            //      row represent the no. of soldiers in that row)
            mat[i][0] = accumulate(mat[i].begin()+1, mat[i].end(), mat[i][0]);

            // storing the no. of soldiers in current row along with the row-number
            pq.push({mat[i][0],i});
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