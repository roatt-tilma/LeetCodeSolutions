class Solution {
public:
    
    int recurse(int i, string s, vector<int>& dp){
        
        if(s[i] == '0') return 0;
        if(i >= s.size() - 1) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        int res = 0;
        
        dp[i] = recurse(i+1, s, dp);
        
        if(s.substr(i, 2) >= "10" && s.substr(i, 2) <= "26") dp[i] += recurse(i+2, s, dp);
        
        return dp[i];
    }
    
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        
        
        
        return recurse(0, s, dp);
    }
};