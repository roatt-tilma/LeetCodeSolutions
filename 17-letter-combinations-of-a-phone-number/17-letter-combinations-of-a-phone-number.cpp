class Solution {
public:
    
    void recurse(string digits, map<char,vector<char>>& mp, vector<string>& ans, string str, int index){
        
        if(digits.size() == 0) return;
        
        if(index >= digits.size()){
            ans.push_back(str);
            return;
        }
        
        for(auto i: mp[digits[index]]){
            str.push_back(i);
            recurse(digits, mp, ans, str, index+1);
            str.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, vector<char>> mp {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };
        
        recurse(digits, mp, ans, "", 0);
        
        return ans;
        
    }
};