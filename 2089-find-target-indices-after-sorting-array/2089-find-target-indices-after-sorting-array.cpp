class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        
        int l = 0;
        int r = nums.size()-1;
        int left = -1;
        int right = -1;
        
        while(l <= r){
            int mid = (l+r) >> 1;
            
            if(target <= nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        
        left = l;
        l = 0;
        r = nums.size()-1;
        
        while(l <= r){
            int mid = (l+r) >> 1;
            
            if(target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        
        right = r;
        
        if(right != -1 && left != -1){
            for(int i = left; i <= right; i++){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};