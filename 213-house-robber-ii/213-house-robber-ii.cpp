class Solution {
public:
    int recurse(vector<int>& nums, int i, int st, vector<int>& dp){
        
        if((i > nums.size()-1 && st == 1) || (i > nums.size()-2 && st == 0)) return 0;
        
        if(dp[i] != -1) return dp[i];

        dp[i] = max(recurse(nums, i+2, st, dp) + nums[i], recurse(nums, i+1, st, dp));
        
        return dp[i];
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp0(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        
        return max(recurse(nums, 1, 1, dp1), recurse(nums, 0, 0, dp0));
    }
};