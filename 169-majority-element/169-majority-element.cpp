class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(auto i: nums) mp[i]++;
        
        for(auto pair: mp){
            if(pair.second > nums.size()/2) return pair.first;
        }
        
        return false;
    }
};