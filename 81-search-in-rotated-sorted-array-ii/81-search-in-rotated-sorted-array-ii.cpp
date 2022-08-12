class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target) return true;
            
            if(nums[l] == nums[r]){
                if(nums[l] == target) return true;
                l++;
                r--;
                continue;
            }
                        
            if(nums[mid] <= nums[r]){
                if(nums[mid] < target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            } else {
                if(nums[mid] > target && target >= nums[l]) r = mid - 1;
                else l = mid + 1;
            } 
        }
        
        return false;
    }
};