class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int len = s.size();
        for (int i = 0; i < len; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push_back(s[i]);
            }
            else{
                if (stack.size() == 0) return false;
                if (s[i] == ')' && stack.back() != '(' 
                    || s[i] == '}' && stack.back() != '{'
                    || s[i] == ']' && stack.back() != '['){
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