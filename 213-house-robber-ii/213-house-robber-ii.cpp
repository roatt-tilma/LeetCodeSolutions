class Solution {
public:
    int recurse(vector<int>& nums, int i, vector<int>& dp){
        
        if(i > nums.size()-1) return 0;
        
        if(dp[i] != -1) return dp[i];

        dp[i] = max(recurse(nums, i+2, dp) + nums[i], recurse(nums, i+1, dp));
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size(), -1);
        
        int takeFirst = recurse(nums, 1, dp);
        
        fill(dp.begin(), dp.end(), -1);
        nums.pop_back();
        
        int takeSecond = recurse(nums, 0, dp);
        
        return max(takeFirst, takeSecond);
    }
};