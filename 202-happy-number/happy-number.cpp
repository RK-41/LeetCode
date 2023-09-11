/*
11.09.23
202. Happy Number   (Easy)

*/
class Solution {
public:
    bool isHappy(int n) {
        // 11.09.23
        
        if(n==1 || n==10)   return true;
        
        unordered_map<int,int> sq;
        set<int> st;
        
        for(int i=1; i<10; i++){
            sq[i] = i*i;
        }
        
        while(true){
            if(n==1 || n==10 || n==7)
                return true;

            if(n<10)    
                return false;

            if(st.find(n) != st.end())
                return false;
               
            st.insert(n);
            
            int dss=0;
            // dss: digit-sq-sum
            
            while(n > 0){
                dss += sq[n%10];
                n/=10;
            }
            
            n = dss;
        }
    }
};