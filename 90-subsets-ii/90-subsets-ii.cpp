class Solution {
public:
    
    void recurse(vector<int>& nums, vector<int> subset, int ind, int N, vector<vector<int>>& ans){
        if(ind == N){
            sort(subset.begin(), subset.end());
            if(find(ans.begin(), ans.end(), subset) == ans.end()) ans.push_back(subset);
            return;
        }
        
        subset.push_back(nums[ind]);
        recurse(nums, subset, ind+1, N, ans);
        subset.pop_back();
        recurse(nums, subset, ind+1, N, ans);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        recurse(nums, subset, 0, nums.size(), ans);
        
        return ans;
    }
};