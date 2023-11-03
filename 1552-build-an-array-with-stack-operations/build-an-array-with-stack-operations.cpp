class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // 03.11.23 POTD
        // APPROACH: Considering an abstract stack having operations 'Push' and 'Pop'
        
        vector<string> ans;
        int stackSize = -1;

        // Iterating the stream of integers in the range [1, n]
        for(int curr_num=1; curr_num<=n; curr_num++){
            // Pushing current number to the abstract stack
            ans.push_back("Push");
            stackSize++;

            // If current number equals target's last element, the required operations are done
            if(curr_num == target.back())   break;

            // If top of stack (current number) isn't equal to the target vector's
            //  current element, pop the abstract stack
            if(curr_num != target[stackSize]){
                ans.push_back("Pop");
                stackSize--;
            }
        }

        return ans;
    }
};