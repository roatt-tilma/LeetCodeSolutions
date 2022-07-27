class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int count = 0;
        
        for(auto i: nums){
            if(count == 0) ele = i;
            if(ele == i) count++;
            else count--;
        }
        
        return ele;
    }
};