class Solution {
public:
    
    int countUPath(int m, int n, vector<vector<int>>& dp){
        if(m == 0 || n == 0) return 0;
        if(m == 1 && n == 1) return 1;
        
        if(dp[m][n] == -1){
            dp[m][n] = countUPath(m-1, n, dp) + countUPath(m, n-1, dp);
            dp[n][m] = dp[m][n];
        }
    
        return dp[m][n];
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+n, vector<int> (m+n, -1));
        return countUPath(m, n, dp);
        
//         int minimum = min(m-1,n-1);
        
//         double ans = 1;
        
//         for(int i = 1; i <= minimum; i++){
//             ans = ans * (m+n-2-minimum+i)/i;
//         }
        
//         return (int)ans;
        
    }
};