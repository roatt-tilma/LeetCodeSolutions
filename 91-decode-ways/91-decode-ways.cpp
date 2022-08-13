class Solution {
public:
    
    int recurse(int i, string s, vector<int>& dp){
        
        if(s[i] == '0') return 0;
        if(i >= s.size() - 1) return 1;
        
        if(dp[i] != -1) return dp[i];

        dp[i] = recurse(i+1, s, dp);
        
        if(s.substr(i, 2) >= "10" && s.substr(i, 2) <= "26") dp[i] += recurse(i+2, s, dp);
        
        return dp[i];
    }
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n+1, -1);
        
        dp[n] = 1;
        
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '0') dp[i] = 0;
            else{ 
                dp[i] = dp[i+1];
                if(i < n-1 && s.substr(i,2) >= "10" && s.substr(i,2) <= "26"){
                    dp[i] += dp[i+2];
                }
            }
        }
        
        return dp[0];
        
        // return recurse(0, s, dp);
    }
};