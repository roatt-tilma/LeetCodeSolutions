class Solution {
public:
    
    int recurse(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp){
        if(i >= triangle.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = triangle[i][j] + min(recurse(triangle, i+1, j, dp), recurse(triangle, i+1, j+1, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size()+1, vector<int>(triangle.size()+1, -1));
        return recurse(triangle, 0, 0, dp);
    }
};