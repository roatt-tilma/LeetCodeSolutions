class Solution {
public:
    
    int getSwapIndex(int i, int l, vector<int> nums){
        int comp = nums[l];
        
        int swapIndex = i;
        
        for(int j = i; j < nums.size(); j++){
            if(nums[j] > comp && nums[j] <= nums[swapIndex]) swapIndex = j;
        }
        
        
        return swapIndex;
    }
    
    void nextPermutation(vector<int>& nums) {
        
        for(int i = nums.size() - 1; i >= 0; i--){
            int l = i - 1;
            
            if(l < 0){
                sort(nums.begin(), nums.end());
                break;
            };  
            
            if(nums[i] > nums[l]){
                
                int swapIndex = getSwapIndex(i, l, nums);
                
                int temp = nums[swapIndex];
                nums[swapIndex] = nums[l];
                nums[l] = temp;
                
                reverse(nums.begin() + i, nums.end());
                break;
            }
        }
        
        
    }
};