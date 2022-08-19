class Solution {
public:
    
    int recurse(int n, vector<int>& dp){
        if(n < 2) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
    }
    
    
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return recurse(n, dp);
    }
};