class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r){
            int mid = (l+r) >> 1;
            if(nums[l] <= nums[mid]){
                if(nums[l] < nums[r]) r = mid;
                else if(nums[l] > nums[r]) l = mid + 1;
                else if(nums[l] == nums[r] && l != r) r--;
            } else {
                r = mid;
            }
        }
        
        return nums[l];
    }
};