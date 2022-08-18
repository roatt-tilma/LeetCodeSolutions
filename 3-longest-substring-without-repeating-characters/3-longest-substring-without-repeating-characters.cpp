class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0) return 0;
        else if(s.size() == 1) return 1;
        
        int i = 0;
        int j = 1;
        
        int count = 1;
        
        while(j < s.size()){
            for(int k = j-1; k >= i; k--){
                if(s[k] == s[j]){
                    count = max(count, j - i);
                    i = k + 1;
                    break;
                }    
            }
            
            j++;
        }
        
        count = max(count, j-i);
        
        return count;
    }
};