class Solution {
public:
    
    int recurse(int ind, vector<int> nums, vector<int>& dp){
        if(ind > nums.size()-1) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        dp[ind] = max(recurse(ind+2, nums, dp) + nums[ind], recurse(ind+1, nums, dp));
        
        return dp[ind];
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(40000, -1); 
        
        return recurse(0, nums, dp);
    }
};