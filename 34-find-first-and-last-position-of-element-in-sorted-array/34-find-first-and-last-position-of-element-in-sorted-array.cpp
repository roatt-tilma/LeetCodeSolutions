class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int flag = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target && flag == 0){
                ans[0] = i;
                ans[1] = i-1;
                flag = 1;
            }
            if(nums[i] == target){
                ans[1]++;
            }
        }
        
        return ans;
    }
};