class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        
        for(auto ch: s){
            if(ch == ' '){
                if(word != ""){
                    st.push(word);
                    word = "";
                }
            } else{
                word.push_back(ch);                
            } 
        }
        
        if(word != ""){
            st.push(word);
        }
        
        string ans = "";
        
        while(st.size()){
            ans += st.top() + " ";
            st.pop();
        }
        
        ans.pop_back();
        
        return ans;
        
    }
};