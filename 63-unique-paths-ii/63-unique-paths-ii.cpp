class Solution {
public:
    
    int recurse(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i > m - 1 || j > n - 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int count = 0;
        
        if(j+1 < n && obstacleGrid[i][j+1] != 1) count += recurse(i, j+1, m, n, obstacleGrid, dp);
        if(i+1 < m && obstacleGrid[i+1][j] != 1) count +=  recurse(i+1, j, m, n, obstacleGrid, dp);
          
        dp[i][j] = count;
        
        return count;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return recurse(0,0,m,n,obstacleGrid,dp);
        
    }
};