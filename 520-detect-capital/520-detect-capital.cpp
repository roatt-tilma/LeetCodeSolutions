class Solution {
public:
    bool detectCapitalUse(string word) {
        int case1 = false;
        int case2 = false;
        int case3 = false;
        
        if (word[0] <= 'Z' && word[0] >= 'A')case1 = true;
        else case2 = true;
        
        for(int i = 1; i < word.size(); i++){
            if(case1){
                if(word[i] <= 'z' && word[i] >= 'a'){
                    if (i != 1) return false;
                    case3 = true;
                    case1 = false;
                }
            }
            if(case2 && word[i] <= 'Z' && word[i] >= 'A') return false;
            if (case3 && word[i] <= 'Z' && word[i] >= 'A') return false;
        }
        return true;
    }
};