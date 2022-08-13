class Solution {
public:
    
    struct node{
      int value = -1;  
    };
    
    int recurse(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return grid[i][j];    
        }
        
        if(i == grid.size() || j == grid[0].size()){
            return 20001;
        } 
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int sum1 = recurse(i+1, j, grid, dp);
        int sum2 = recurse(i, j+1, grid, dp);
        
        dp[i][j] = grid[i][j] + min(sum1, sum2);
        
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(201, vector<int>(201, -1));
        
        return recurse(0, 0, grid, dp);
    }
};