class Solution {
public:
    int mySqrt(int x) {
        //compare with x, search from 0 to x
        
        if(x == 1) return 1;
        
        int l = 0;
        int r = x/2;
        
        while(l <= r){
            long long mid = (l+r)/2;
            
            long long sq = mid*mid;
            
            if(sq == x) return mid;
            
            if(sq > x) r = mid - 1;
            if(sq < x) l = mid + 1;
        }
        
        return r;
        
    }
};