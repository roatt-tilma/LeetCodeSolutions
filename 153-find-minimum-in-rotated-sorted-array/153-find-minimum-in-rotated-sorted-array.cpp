class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r){
            
            if(nums[l] <= nums[r]) return nums[l];
            
            
            int mid = (l+r) >> 1;
            
            if(nums[l] <= nums[mid]) l = mid + 1;
            else r = mid;
        }
        
        return nums[l];
    }
};