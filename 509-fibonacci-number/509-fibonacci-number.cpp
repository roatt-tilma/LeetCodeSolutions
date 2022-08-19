class Solution {
public:
    
    int recurse(int n, vector<int>& dp){
        if(n < 2) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = recurse(n-1, dp) + recurse(n-2, dp);
    }
    
    
    int fib(int n) {
        // vector<int> dp(n+1);
        
        if(n < 2) return n;
        
        // dp[0] = 0;
        // dp[1] = 1;
        
        int pre1 = 0;
        int pre2 = 1;
        int ans = pre1 + pre2;
        
        for(int i = 2; i < n+1; i++){
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        
        return ans;
        
        // return recurse(n, dp);
    }
};