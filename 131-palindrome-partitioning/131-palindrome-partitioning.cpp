class Solution {
public:
    
    bool isPalindrome(string s, int start, int end, vector<vector<int>>& dp){
        
        if(dp[start][end] == -1) return false;
        if(dp[start][end] == 1) return true;
        
        int l = start;
        int r = end;
            
        while(start <= end){
            if(s[start++] != s[end--]){
                // dp[start][end] = -1;
                return false; 
            }    
        }
        
        // dp[l][r] = 1;
        return true;
    }
    
    void recurse(string s, vector<string> substrings, vector<vector<string>>& ans, int st, vector<vector<int>>& dp){
        if(st == s.size()){
            ans.push_back(substrings);
            return;
        } 
        
        for(int i = st; i < s.size(); i++){
            if(isPalindrome(s, st, i, dp)){
                substrings.push_back(s.substr(st, i - st + 1));
                recurse(s, substrings, ans, i+1, dp);
                substrings.pop_back(); 
            } 
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        
        vector<vector<int>> dp(20, vector<int> (20, 0));
        
        recurse(s, substrings, ans, 0, dp);
        
        return ans;
    }
};