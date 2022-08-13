#include<bits/stdc++.h>

class Solution {
public:
    
    bool isTargetSum(vector<int>& nums, int targetSum, int i, vector<vector<int>>& dp){ 
        if(targetSum == 0) return true;
        if(targetSum < 0 || i >= nums.size()) return false;
        
        if(dp[i][targetSum] != -1) return dp[i][targetSum];
        
        dp[i][targetSum] = isTargetSum(nums, targetSum - nums[i], i+1, dp) || isTargetSum(nums, targetSum, i+1, dp);
        return dp[i][targetSum];
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(20000, -1));
        
        if(totalSum%2 == 1) return false;
        
        int targetSum = totalSum/2;
        
        return isTargetSum(nums, targetSum, 0, dp);
    }
};