class Solution {
public:
    
    void recurse(vector<int>& nums, vector<int> subset, int ind, int N, vector<vector<int>>& ans){
        
        if(ind == N){
            return;
        }
        
        int last = INT_MIN;
        
        for(int i = ind; i < N; i++){  
            if(last != nums[i]){
                last = nums[i];
                subset.push_back(nums[i]);
                ans.push_back(subset);
                recurse(nums, subset, i+1, N, ans);
                subset.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        ans.push_back(subset);
        recurse(nums, subset, 0, nums.size(), ans);
        
        return ans;
    }
};