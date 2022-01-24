class Solution {
public:
    int dp[1000][1000];
    int maxProduct(vector<int>& nums, vector<int>& multipliers, int i, int l, int r, int mul){
        if (i == multipliers.size()-1) return nums[mul]*multipliers[i]; 
        int newSum = nums[mul]*multipliers[i];
        if(dp[l][i] == -1) dp[l][i] = max(maxProduct(nums, multipliers, i+1, l+1, r, l), maxProduct(nums, multipliers, i+1, l, r-1, r));
        return dp[l][i] + newSum;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp, -1, sizeof(dp));
        int i = 0, l = 0, r = nums.size()-1;
        return max(maxProduct(nums, multipliers, i, l+1, r, l), maxProduct(nums, multipliers, i, l, r-1, r));
    }
};