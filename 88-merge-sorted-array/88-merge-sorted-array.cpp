class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        
        if(n == 0) return;
        
        if(m != 0){
            for(int i = 0; i < m; i++){
                if(nums1[i] > nums2[0]){
                    swap(nums1[i], nums2[0]);
                    for(int j = 1; j < n; j++){
                        if(nums2[j] < nums2[j-1]) swap(nums2[j], nums2[j-1]);
                        else break;
                    }
                }
            }    
        }
        
        
        for(int i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }
    }
};