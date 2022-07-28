class Solution {
public:
    
    int countUPath(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i == m || j == n) return 0;
        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j] == -1) dp[i][j] = countUPath(m, n, i+1, j, dp) + countUPath(m, n, i, j+1, dp);
    
        return dp[i][j];
    }
    
    
    int uniquePaths(int m, int n) {
        //vector<vector<int>> dp(m, vector<int> (n, -1));
        //return countUPath(m, n, 0, 0, dp);
        
        int minimum = min(m-1,n-1);
        
        double ans = 1;
        
        for(int i = 1; i <= minimum; i++){
            ans = ans * (m+n-2-minimum+i)/i;
        }
        
        return (int)ans;
        
    }
};