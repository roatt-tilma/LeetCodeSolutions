class Solution {
public:
    
    int dp[100][100];
    
    int countUPath(int m, int n, int i, int j){
        if(i == m || j == n) return 0;
        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j] == -1) dp[i][j] = countUPath(m, n, i+1, j) + countUPath(m, n, i, j+1);
    
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return countUPath(m, n, 0, 0);
    }
};