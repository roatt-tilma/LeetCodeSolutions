class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tempProduct = 1;
        int maxProduct = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(tempProduct == 0) {
                tempProduct = 1;
            }
            tempProduct *= nums[i];
            maxProduct = max(maxProduct, tempProduct);
        }

        tempProduct = 1;

        for(int i = nums.size() - 1; i >= 0; i--){
            if(tempProduct == 0) {
                tempProduct = 1;
            }
            tempProduct *= nums[i];
            maxProduct = max(maxProduct, tempProduct);
        }
        
        return maxProduct;
    }
};