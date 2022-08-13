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
        vector<int> dp(n+2, -1);
        return recurse(0, n, dp);    
    }
};