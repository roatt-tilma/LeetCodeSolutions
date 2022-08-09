class Solution {
public:
    
    int recurse(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(i > m - 1 || j > n - 1 || obstacleGrid[i][j] == 1) return 0;
        
        if(i == m-1 && j == n-1){
            return 1;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int count = 0;
        
        count += recurse(i, j+1, obstacleGrid, dp);
        count += recurse(i+1, j, obstacleGrid, dp);
          
        dp[i][j] = count;
        
        return count;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        
        return recurse(0,0,obstacleGrid,dp);
        
    }
};