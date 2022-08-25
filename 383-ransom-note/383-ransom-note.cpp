class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> magazineMap;
        
        for(auto letter: magazine){
            magazineMap[letter]++;
        }
        
        for(auto letter: ransomNote){
            if(magazineMap[letter]-- <= 0) return false;
        }
        
        return true;
    }
};