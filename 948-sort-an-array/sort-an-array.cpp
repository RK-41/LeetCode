class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 25.07.24 potd
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }

private:
    void mergeSort(vector<int>& arr, int low, int high){
        if(low >= high)
            return;

        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int>& arr, int low, int mid, int high){
        int n1 = mid-low+1, n2 = high-mid;
        vector<int> leftPart(n1), rightPart(n2);

        for(int i=0; i<n1; i++){
            leftPart[i] = arr[low+i];
        }

        for(int i=0; i<n2; i++){
            rightPart[i] = arr[mid+1+i];
        }

        int p1 = 0, p2 = 0, writeIdx = low;
        while(p1<n1 && p2<n2){
            if(leftPart[p1] <= rightPart[p2])
                arr[writeIdx] = leftPart[p1++];
            else
                arr[writeIdx] = rightPart[p2++];

            ++writeIdx;
        }

        while(p1 < n1){
            arr[writeIdx++] = leftPart[p1++];
        }

        while(p2 < n2){
            arr[writeIdx++] = rightPart[p2++];
        }
    }
};