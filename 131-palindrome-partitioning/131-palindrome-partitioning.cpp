class Solution {
public:
    
    unordered_map<string, int> dp;
    
    bool isPalindrome(string s){
        
        if(dp[s] == 1) return true;
        if(dp[s] == -1) return false;
        
        int l = 0;
        int r = s.size() - 1;
        
        while(l < r){
            if(s[l] != s[r]){
              return false;  
            } 
            l++;
            r--;
        }
        
        dp[s] = 1;
        return true;
    }
    
    void recurse(string s, vector<string> substrings, vector<vector<string>>& ans, int stringSize, int st){
        if(st == stringSize){
            ans.push_back(substrings);
            return;
        } 
        
        for(int i = 1; i <= stringSize - st; i++){
            string potPalindrome = s.substr(st, i);
            if(!isPalindrome(potPalindrome)) continue;
            substrings.push_back(potPalindrome);
            recurse(s, substrings, ans, stringSize, st+i);
            substrings.pop_back();
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        
        recurse(s, substrings, ans, s.size(), 0);
        
        return ans;
    }
};