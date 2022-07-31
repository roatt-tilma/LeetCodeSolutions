class Solution {
public:
    
    void recurse(int target, int size, int sum, int st, vector<int>& array, vector<vector<int>>& ans, vector<int> subset){
        
        if(sum >= target){
            if(sum == target) ans.push_back(subset);
            return;
        }
        
        for(int i = st; i < size; i++){
            if(sum > target) break;
            sum += array[i];
            subset.push_back(array[i]);
            cout<<sum<<"\n";
            for(auto j: subset) cout<<j<<" ";
            cout<<"\n";
            recurse(target, size, sum, i, array, ans, subset);
            sum -= array[i];
            subset.pop_back();
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<vector<int>> ans;
        
        recurse(target, candidates.size(), 0, 0, candidates, ans, subset);
            
        return ans;
    }
};