class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kk;
public:
    KthLargest(int k, vector<int>& nums) {
        // 12.08.24 POTD
        kk = k;
        for(auto n: nums){
            minHeap.push(n);
            if(minHeap.size() > k)
                minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > kk)
            minHeap.pop();

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */