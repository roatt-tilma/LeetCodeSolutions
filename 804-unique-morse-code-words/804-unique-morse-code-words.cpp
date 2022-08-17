class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> diffTransformation;
        vector<string> code {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto i: words){
            string temp = "";
            for(auto j: i){
                temp += code[j-'a'];
            }
            diffTransformation.insert(temp);
        }
        
        return diffTransformation.size();
    }
};