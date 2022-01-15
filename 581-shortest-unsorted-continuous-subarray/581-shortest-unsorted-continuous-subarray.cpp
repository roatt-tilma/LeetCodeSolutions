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
    }
};