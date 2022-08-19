class Solution {
public:
    
    int recurse(int i, int n, vector<int>& dp){
        if(i == n ) return 1;
        if(i > n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        dp[i] = recurse(i+1, n, dp) + recurse(i+2, n, dp);
        return dp[i];
    }
    
    
    int climbStairs(int n) {
        
        if(n <= 2) return n;
        
        vector<int> dp(n+1);
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i < n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
        
        // return recurse(0, n, dp);    
    }
};