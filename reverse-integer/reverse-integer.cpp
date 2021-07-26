class Solution {
public:
    int reverse(int x) {
        int negative = 0;
        
        if (x == -2147483648) return 0;
        
        if(x < 0){
            x = -1*x;
            negative = 1;
        }
        
        int ans = 0;
        int count = 0;
        
        while(x){
            ans = ans*10 + x%10;
            x = x/10;
            count++;
            
            if (count == 9 && x != 0){
                if(ans > 214748364) return 0;
                else if(ans == 214748364){
                        if(negative == 0 && x%10 > 7) return 0;
                        else if (x%10 > 8) return 0;
                }    
            }
        }
        
        if(negative) ans = -1*ans;
        
        return ans;
    }
};