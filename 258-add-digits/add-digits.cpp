class Solution {
public:
    int addDigits(int num) {
        // 16.09.23 
        
        if(num<10)  return num;

        int sum = 0;
        while(true){
            sum += num%10;
            num /= 10;

            if(num==0){
                if(sum>9){
                    num=sum;
                    sum=0;
                }
                else
                    return sum;
            }
        }
    }
};