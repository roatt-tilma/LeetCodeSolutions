class Solution {
public:
    
    int recurse(vector<int>& nums, int target, int sum, vector<int>& dp){
        if(sum == target){
            return 1;
        }
        
        if(dp[sum] != -1) return dp[sum];
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > target) break;
            
            count += recurse(nums, target, sum + nums[i], dp);                
        }
        
        dp[sum] = count;
        
        return count;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<int> dp(10e5, -1);
        
        return recurse(nums, target, 0, dp);
    }
};