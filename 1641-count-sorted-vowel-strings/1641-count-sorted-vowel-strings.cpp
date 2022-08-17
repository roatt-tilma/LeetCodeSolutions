class Solution {
public:
    
    int recurse(int n, int start, vector<vector<int>>& dp){
        if(n == 0) return 1;
        
        if(dp[n][start] != -1) return dp[n][start];
        
        int count = 0;
        
        for(int i = start; i < 5; i++){
            count += recurse(n-1, i, dp);
        }
        
        return dp[n][start] = count;
    }
    
    int countVowelStrings(int n) {
        
        vector<vector<int>> dp(n+1, vector<int>(6, -1));
        
        return recurse(n, 0, dp);
    }
};