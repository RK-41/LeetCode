class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // 05.11.23 POTD

        if(k >= arr.size()-1)
            return *max_element(arr.begin(), arr.end());

        int kk = 0;
        deque<int> d;

        for(auto a: arr)
            d.push_back(a);

        while(true){
            int a0 = d.front();
            d.pop_front();

            if(a0 > d.front()){
                d.push_back(d.back());
                d.pop_front();
                d.push_front(a0);
                kk++;
            }
            else{
                d.push_back(a0);
                kk=1;
            }

            if(kk == k)
                break;
        }

        return d.front();
    }
};