class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int medInd = (nums1.size() + nums2.size())/2;
        
        if((nums1.size() + nums2.size())%2 == 1){
            int a = 0;
            int b = 0;
            int count = 0;
            
            double median;
            
            while(a < nums1.size() && b < nums2.size()){
                if(count == medInd+1) return median;
                if(nums1[a] < nums2[b]) median = nums1[a++];
                else median = nums2[b++];
                count++;
            }
            
            while(a < nums1.size()){
                if(count == medInd+1) return median;
                median = nums1[a++];
                count++;
            }
            
            while(b < nums2.size()){
                if(count == medInd+1) return median;
                median = nums2[b++];
                count++;
            }
        } else {
            int a = 0;
            int b = 0;
            int count = 0;
            int flag = 0;

            double median;
            
            while(a < nums1.size() && b < nums2.size()){
                
                if(nums1[a] < nums2[b]) median = nums1[a++];
                else median = nums2[b++];
                
                count++;
                
                if(count == medInd){
                    flag = 1;
                    break;
                } 
            }
            
            if(flag){
                if(a < nums1.size() && b < nums2.size() && nums1[a] < nums2[b]) return (median + nums1[a])/2;
                else if(a < nums1.size() && b < nums2.size() && nums1[a] >= nums2[b]) return (median + nums2[b])/2;
                else if(a < nums1.size()) return (median + nums1[a])/2;
                else if(b < nums2.size()) return (median + nums2[b])/2;
            }
            
            while(a < nums1.size()){

                median = nums1[a++];

                count++;
                
                if(count == medInd){
                  flag = 1;
                    break;
                } 
            }
            
            if(flag){
                if(a < nums1.size()) return (median + nums1[a])/2;
            }
            
            while(b < nums2.size()){
                
                median = nums2[b++];
                
                count++;
                
                if(count == medInd){
                    flag = 1;
                    break;
                }
            }
            
            if(flag){
                if(b < nums2.size()) return (median + nums2[b])/2;
            }
        }
        
        if(nums1.size() == 1) return nums1[0];
        return nums2[0];
    }
};