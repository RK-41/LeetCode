class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 10.10.23 potd

        // Store the input vector size
        int n = nums.size();

        // Initialize the 'ans' to the max possible integer value
        int ans = numeric_limits<int>::max();

        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());

        // Create a new vector 'uniqueNums' with unique elements from 'nums'
        // This step removes duplicate values from the sorted 'nums' vector
        vector<int> uniqueNums(nums.begin(), unique(nums.begin(), nums.end()));

        // Iterate through the 'uniqueNums' vector
        for(int i=0; i<uniqueNums.size(); ++i){
            // Calculate the start value 's' for the subsequence
            int s = uniqueNums[i];

            // Calculate the end value 'e' for the subsequence
            int e = s+n-1;

            // Find the iterator 'it' pointing to the first element in 'uniqueNums'
            //  that is greater than 'e' using binary search
            auto it = upper_bound(uniqueNums.begin(), uniqueNums.end(), e);

            // Calculate the index 'idx' of 'it' in 'uniqueNums'
            int idx = distance(uniqueNums.begin(), it);

            // Update 'ans' by minimizing it with the diff between 'n' 
            //  and the distance between 'it' & the curr index 'i'
            ans = min(ans, n-(idx-i));
        }

        // Finally, return the 'ans' which is min no. of operations required
        return ans;
    }   
};