class Solution {
public:
    
    bool find(vector<int>& stones, int target){
        int l = 0;
        int r = stones.size() - 1;
        
        while(l <= r){
            int mid = (l+r) >> 1;
            if(stones[mid] == target) return true;
            if(target > stones[mid]) l = mid + 1;
            else r = mid - 1;
        }
        
        return false;
    }
    
    bool recurse(vector<int>& stones, int i, int prev, map<pair<int,int>, int>& dp){
        
        if(i == stones[stones.size()-1]) return true;
        if(i > stones[stones.size()-1] || prev <= 0) return false;
        
        if(dp.find({i, prev}) != dp.end()) return dp[{i,prev}];
        
        if(find(stones, i)){
            return dp[{i,prev}] = recurse(stones, i+prev, prev, dp) || recurse(stones, i+prev+1, prev+1, dp) || recurse(stones, i+prev-1, prev-1, dp);
        }
        
        return dp[{i,prev}] = false;
        
    }
    
    

    bool canCross(vector<int>& stones) {
        
        map<pair<int,int>, int> dp;
        
        return recurse(stones, 1, 1, dp);
    }
};