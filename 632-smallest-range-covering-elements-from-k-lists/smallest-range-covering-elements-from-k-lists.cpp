class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // 13.10.24 potd
        // Min-heap: stores (val, list idx, ele idx)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int currMax = numeric_limits<int>::min();

        // Init the heap withe first ele of each list
        for(int i=0; i<nums.size(); i++){
            minHeap.push({nums[i][0], i, 0});
            currMax = max(currMax, nums[i][0]);
        }

        // Track smallest range
        vector<int> smallRange = {0, numeric_limits<int>::max()};

        while(!minHeap.empty()){
            // Get min ele form the heap
            vector<int> curr = minHeap.top();
            minHeap.pop();
            int currMin = curr[0], listIdx = curr[1], eleIdx = curr[2];

            // Update smallest range if a beffer one is found
            if((currMax - currMin < smallRange[1] - smallRange[0]) || (currMax - currMin == smallRange[1] - smallRange[0] && currMin < smallRange[0])){
                smallRange[0] = currMin;
                smallRange[1] = currMax;
            }

            // Move to the next ele in the same list
            if(eleIdx + 1 < nums[listIdx].size()){
                int nextVal = nums[listIdx][eleIdx+1];
                minHeap.push({nextVal, listIdx, eleIdx+1});
                currMax = max(currMax, nextVal);
            } else {
                // If any list is exhausted, stop
                break;
            }
        }

        return smallRange;
    }
};