class Solution {
public:
    
    int recurse(int ind, string s, vector<int>& dp){
        if(ind == s.size()) return 1;
        
        if(s[ind] == '0') return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int res = recurse(ind+1, s, dp);
        if(ind < s.size() - 1 && (s[ind] == '1' || (s[ind] == '2'&& s[ind+1] < '7'))) res += recurse(ind+2, s, dp);
        
        dp[ind] = res;
        
        return res;
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return recurse(0, s, dp);
    }
};