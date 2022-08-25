class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> magazineMap;
        map<char,int> ransomNoteMap;
        
        for(auto letter: magazine){
            magazineMap[letter]++;
        }
        
        for(auto letter: ransomNote){
            ransomNoteMap[letter]++;
        }
        
        for(auto i: ransomNoteMap){
            if(i.second > magazineMap[i.first]) return false; 
        }
        
        return true;
    }
};