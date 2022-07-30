#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int flag = 0;
        
        vector<int> temp = nums;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        
        while(nums[i] + nums[j] != target){
            if(nums[i] + nums[j] > target) --j;
            if(nums[i] + nums[j] < target) ++i;
        }
        
        
        for(int k = 0; k < temp.size(); k++){
            if(temp[k] == nums[i]){
                ans[0] = k;
                break;
            }
        }
        
        for(int k = temp.size() - 1; k >= 0; k--){
            if(temp[k] == nums[j]){
                ans[1] = k;
                break;
            }
        }
        
        return ans;
        
    }
};
