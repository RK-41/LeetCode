class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        // 21.11.23 potd

        unordered_map<int,int> numbers;

        for(int n: nums){
            int temp = n - reverse(n);

            if(numbers.find(temp) != numbers.end()){
                numbers[temp]++;
            } else {
                numbers[temp] = 1;
            }
        }

        long result = 0;
        int mod = 1000000007;
        for(const auto& entry: numbers){
            result = (result % mod + ((long)entry.second * ((long)entry.second-1)/2))%mod;
        }

        return static_cast<int>(result);
    }

    private:
        int reverse(int n){
            int rev = 0;
            while(n>0){
                rev = rev * 10 + n%10;
                n /= 10;
            }

            return rev;
        }
};