class Solution {
public:
    
    int recurse(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        
        if(dp[amount] != -2) return dp[amount];
        
        int count = INT_MAX;
        
        for(int i = 0; i < coins.size(); i++){
            int val = recurse(coins, amount - coins[i], dp);
            if(val != -1){
                count = min(val, count);
            }
        }
        
        return dp[amount] = count == INT_MAX ? -1: count+1;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
        
        return recurse(coins, amount, dp);
    }
};