class Solution {
public:
    
    void recurse(string s, int l, int r, int n, vector<string>& ans){
        
        if(l > n || l < r) return;
        
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        
        s.push_back('(');
        recurse(s, l+1, r, n, ans);
        s.pop_back();
        s.push_back(')');
        recurse(s, l, r+1, n, ans);
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        
        recurse("", 0, 0, n ,ans);
        
        return ans;
    }
};