class Solution {
public:
    
    void recurse(vector<int>& array, vector<vector<int>>& ans, vector<int> subset, int size, int target, int ind){
        if(target == 0){
            ans.push_back(subset);
            return;
        }
        
        int last = array[ind];
        
        for(int i = ind; i < size; i++){
            if(target < 0) break;
            if(i > ind && last == array[i]) continue;
            subset.push_back(array[i]);
            recurse(array, ans, subset, size, target-array[i], i+1);
            subset.pop_back();
            last = array[i];
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        
        sort(candidates.begin(), candidates.end());
        
        
        recurse(candidates, ans, subset, candidates.size(), target, 0);
        
        return ans;
    }
};