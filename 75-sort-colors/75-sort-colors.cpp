class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> count;
        
        for(auto i: nums) count[i]++;
        
        for(int i = 0; i < count[0]; i++) nums[i] = 0;
        for(int i = count[0]; i < count[0]+count[1]; i++) nums[i] = 1;
        for(int i = count[0]+count[1]; i < count[0]+count[1]+count[2]; i++) nums[i] = 2;
        
    }
};