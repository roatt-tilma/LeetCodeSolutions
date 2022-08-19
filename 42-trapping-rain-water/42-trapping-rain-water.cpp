class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        
        int maxL = 0;
        int maxR = 0;
        
        int waterTrapped = 0;
        
        while(l <= r){
            if(height[l] <= height[r]){
                if(height[l] >= maxL) maxL = height[l];
                else waterTrapped += maxL - height[l];
                l++;
            } else {
                if(height[r] >= maxR) maxR = height[r];
                else waterTrapped += maxR - height[r];
                r--;
            }
        }
        
        
        return waterTrapped;
    }
};