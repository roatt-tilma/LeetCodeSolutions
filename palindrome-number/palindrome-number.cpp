class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int rev = 0;
        int original_x = x;
        int count = 0;
        
        while(x){
            rev = rev*10 + x%10;
            x = x/10;
            count++;
            
            if (count == 9 && x != 0){
                if (rev > 214748364) return 0;
                else if (rev == 214748364 && x%10 > 8) return 0;
            }
        }
        
        if (original_x == rev) return true;
        return false;
    }
};