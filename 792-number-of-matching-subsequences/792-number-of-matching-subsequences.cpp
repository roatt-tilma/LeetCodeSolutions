class Solution {
public:
    
    map<string, int> memory; 
    
    bool containsSubsequence(string word, string s){
        
        int limit = s.size();
        int i = 0;
        
        int len = 0;
        
        int flag = 0;
        
        if(memory[word] > 0) return true;
        if(memory[word] < 0) return false;        
        
        
        for(auto ch: word){
            while(i < limit){
                if(ch == s[i]){
                    len++;
                    i++;
                    break;
                }
                i++;
            }
            if(len == word.size()) flag = 1;
        }
        
        if(flag){
            memory[word]++;
            return true;
        } else{
            memory[word]--;
            return false;
        }
    }
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int count = 0;
        
        for(auto word: words){
            if(containsSubsequence(word, s)) count++;    
        }
        
        return count;
    }
};