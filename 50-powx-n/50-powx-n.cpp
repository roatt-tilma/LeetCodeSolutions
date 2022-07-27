class Solution {
public:
    
    double recPow(double x, long long n){
        if(n == 0) return 1;
        
        if(n%2 == 0) return recPow(x*x, n/2);
        else return x*pow(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        
        long long negN = n;
        negN *= -1;
        
        if(n < 0) return 1/recPow(x, negN);

        return recPow(x, n);
    }
};