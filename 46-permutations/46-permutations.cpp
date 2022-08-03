class Solution {
public:
    
    void recurse(vector<int>& nums, vector<int> visited, vector<vector<int>>& ans, vector<int> permutation){
        if(nums.size() == permutation.size()){
            ans.push_back(permutation);
            return; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                permutation.push_back(nums[i]);
                recurse(nums, visited, ans, permutation);
                permutation.pop_back();
                visited[i] = 0;
            }
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> visited(nums.size(), 0);
        vector<int> permutation;
        
        recurse(nums, visited, ans, permutation);
        
        return ans;
    }
};