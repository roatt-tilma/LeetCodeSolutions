class Solution {
public:
    
    unordered_map<string, int> dp;
    
    bool isPalindrome(string s, int start, int end){
        
        while(start <= end){
            if(s[start++] != s[end--]){
                return false; 
            }    
        }

        return true;
    }
    
    void recurse(string s, vector<string> substrings, vector<vector<string>>& ans, int st){
        if(st == s.size()){
            ans.push_back(substrings);
            return;
        } 
        
        for(int i = st; i < s.size(); i++){
            if(isPalindrome(s, st, i)){
                substrings.push_back(s.substr(st, i - st + 1));
                recurse(s, substrings, ans, i+1);
                substrings.pop_back(); 
            } 
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substrings;
        
        recurse(s, substrings, ans, 0);
        
        return ans;
    }
};