class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // 01.01.26 potd
        vector<int> ans;
        int flg=0, n=digits.size(), x, c=1;
        for(int i=0; i<n; i++)
        {
            x=digits[n-1-i]+c;
            if(x==10)
            {
                ans.push_back(0);
                c=1;
                if(i==n-1)
                    flg=1;
            }
            else
            {
               ans.push_back(x);
               c=0;
            }
        }
        if(flg)
            ans.push_back(c);
    
        reverse(ans.begin(), ans.end());
        return ans;
    }
};