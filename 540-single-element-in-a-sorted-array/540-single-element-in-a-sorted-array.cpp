class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        
        while(l <= r){
            mid = (l+r)/2;
            
            if(mid == 0 || mid == nums.size()-1) break;
            
            if(nums[mid-1] == nums[mid]){
                if(mid%2 == 0) r = mid - 1;
                else l = mid + 1;
            } else if (nums[mid+1] == nums[mid]){
                if(mid%2 == 0) l = mid + 1;
                else r = mid - 1;
            } else{
                break;
            }
        }
        
        return nums[mid];
    }
};