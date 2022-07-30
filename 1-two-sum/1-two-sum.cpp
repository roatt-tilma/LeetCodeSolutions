#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> hash; 
        
        for(int i = 0; i < nums.size(); i++){
            if(hash.find(target - nums[i]) != hash.end() && hash[target - nums[i]] != i){
                ans[0] = i;
                ans[1] = hash[target - nums[i]];
                break;
            } else{
                hash[nums[i]] = i;
            }
        }
        
        return ans;
        
        
    }
};
