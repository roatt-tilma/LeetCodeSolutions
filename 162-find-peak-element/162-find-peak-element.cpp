class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size() - 1;
        
        while(l < r){
            
            int mid1 = (l+r) >> 1;
            int mid2 = mid1 + 1;
            
            if(nums[mid1] < nums[mid2]) l = mid2;
            else r = mid1;
        }
        
        return l;
        
        
//         int low = 0;
//         int high = nums.size()-1;
        
//         while(low < high)
//         {
//             int mid1 = (low+high)/2;
//             int mid2 = mid1+1;
//             if(nums[mid1] < nums[mid2])
//                 low = mid2;
//             else
//                 high = mid1;
//         }
//         return low;
        
    }
};