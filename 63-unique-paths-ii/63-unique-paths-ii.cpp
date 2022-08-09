class Solution {
public:
    
    int recurse(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        
        if(i > m - 1 || j > n - 1 || obstacleGrid[i][j] == 1) return 0;
        
        if(i == m-1 && j == n-1){
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int count = 0;
        
        count += recurse(i, j+1, m, n, obstacleGrid, dp);
        count += recurse(i+1, j, m, n, obstacleGrid, dp);
          
        dp[i][j] = count;
        
        return count;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return recurse(0,0,m,n,obstacleGrid,dp);
        
    }
};