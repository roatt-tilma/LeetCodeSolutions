class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        
        for(auto i: nums){
            count[i]++;
        }
        
        for(auto i: nums){
            if(count[i] == 0) continue;
           
            count[i]--;
            
            if(end[i-1] > 0){
                end[i-1]--;
                end[i]++;
            } else if (count[i+1] > 0 && count[i+2] > 0){
                count[i+1]--;
                count[i+2]--;
                end[i+2]++;
            } else {
                return false;
            }
        }
        
        return true;
    }
};