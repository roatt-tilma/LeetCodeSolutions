class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int len = s.size();
        char end_brac = ' ';
        for (int i = 0; i < len; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push_back(s[i]);
            }
            else{
                if (stack.size() == 0) return false;
                end_brac = s[i];
                if (end_brac == ')' && stack.back() != '(' 
                    || end_brac == '}' && stack.back() != '{'
                    || end_brac == ']' && stack.back() != '['){
                    return false;
                }else{
                    stack.pop_back();
                }
            }
        }
        if (stack.size() != 0) return false;
        return true;
    }
};