class Solution {
public:
    
    int recurse(int amount, vector<int>& coins, int start, vector<vector<int>>& dp){
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        
        if(dp[amount][start] != -1) return dp[amount][start];
        
        int count = 0;
        
        for(int i = start; i < coins.size(); i++){
            count += recurse(amount-coins[i], coins, i, dp);
        }
        
        return dp[amount][start] = count;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(301, -1));
         
        return recurse(amount, coins, 0, dp);
    }
};