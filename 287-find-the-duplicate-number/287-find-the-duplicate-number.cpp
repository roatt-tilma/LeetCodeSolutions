class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        
        for(auto i: nums){
            if(hash[i] == 1) return i;
            hash[i]++;
       }
        
        return 0;
    }
};