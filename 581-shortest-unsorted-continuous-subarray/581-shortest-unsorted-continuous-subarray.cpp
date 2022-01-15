class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int lflag = 1, rflag = 1;
        while (l < r && (lflag || rflag)){
            if (lflag){
                for (int i = l+1; i < r+1; i++){
                    if (nums[i] >= nums[l]) continue;
                    lflag = 0;
                    break;
                }  
                if (lflag) l++;
            }
            
            if (rflag){
                for (int i = r-1; i > l-1; i--){
                    if (nums[i] <= nums[r]) continue;
                    rflag = 0;
                    break;
                }
                if (rflag) r--;
            }   
        }
        if (lflag) return 0;
        return r - l + 1;
        
        //int l = 0, r = nums.size() - 1;
        
        //for (int i = 0; i < r; i++){
          //  if (nums[i] <= nums[i+1]) continue;
         //   l = i+1;
        //    break;
       // }
        
        //for (int i = l-1; i > 0; i--){
            //if (nums[i] >= nums[l]) continue;
           // l = i+1;
         //   break;
       // }
        
       // if (l==0) return 0;
        
        //for (int i = r; i > 0; i--){
            //if(nums[i] >= nums[i-1]) continue;
           // r = i-1;
         //   break;
       // }
        
       // for (int i = r + 1; i < r; i++){
        //    if (nums[i] < nums[r]) continue;
        //    r = i - 1;
        //    break;
        //}
        
        //return r - l + 3;
    }
};