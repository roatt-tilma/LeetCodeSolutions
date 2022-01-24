class Solution {
public:
    bool detectCapitalUse(string word) {
        int case1 = false;
        int case2 = false;
        int case3 = false;
        
        for(int i = 0; i < word.size(); i++){
            if (i == 0){
                if (word[i] <= 'Z' && word[i] >= 'A'){
                    case1 = true;
                }
                else {
                    case2 = true;
                }
            }
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