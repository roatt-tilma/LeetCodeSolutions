class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        
        pair<int, int> mx;
        
        for(int g = 0; g < s.size(); g++){
            for(int i = 0, j = g; j < s.size(); i++, j++){
                if(g == 0){
                    dp[i][j] = 1;
                    mx = {i, j};
                } else if (g == 1){
                    if(s[i] == s[j]){
                      dp[i][j] = 1;
                      mx = {i,j};

                    } 
                } else {
                    if(s[i] == s[j] && dp[i+1][j-1] == 1){
                        dp[i][j] = 1;
                        mx = {i, j};
                    }
                }
            }    
        }
        
        string ans = s.substr(mx.first, mx.second-mx.first+1);
        
        return ans;
    }
};