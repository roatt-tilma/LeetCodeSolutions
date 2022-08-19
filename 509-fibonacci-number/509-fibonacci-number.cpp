class Solution {
public:
    
    int recurse(int n, vector<int>& dp){
        if(n < 2) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
    }
    
    
    int fib(int n) {
        vector<int> dp(n+1);
        
        if(n < 2) return n;
        
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
        // return recurse(n, dp);
    }
};