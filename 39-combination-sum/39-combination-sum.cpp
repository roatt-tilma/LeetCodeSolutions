class Solution {
public:
    
    void recurse(int target, int sum, int st, vector<int>& candidates, vector<vector<int>>& ans, vector<int> subset){
        
        if(sum == target){
            if(sum == target) ans.push_back(subset);
            return;
        }
        
        for(int i = st; i < candidates.size(); i++){
            if(sum > target) break;
            sum += candidates[i];
            subset.push_back(candidates[i]);
            recurse(target, sum, i, candidates, ans, subset);
            sum -= candidates[i];
            subset.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        
        recurse(target, 0, 0, candidates, ans, subset);
            
        return ans;
    }
};