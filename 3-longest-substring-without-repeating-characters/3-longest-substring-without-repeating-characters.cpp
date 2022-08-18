class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) return 0;
        else if(s.size() == 1) return 1;
        
        int i = 0;
        int j = 1;
        
        int count = 1;
        
        vector<int> hMap(256, -1);
        hMap[s[i]] = i;
        
        while(j < s.size()){
            
            if(hMap[s[j]] >= i){
                count = max(count, j - i);
                i = hMap[s[j]] + 1;
            }
            
            hMap[s[j]] = j;
            j++;
        }
        
        count = max(count, j-i);
        
        return count;
    }
};