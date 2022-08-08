class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string answer = "";
        int charind = 0;
        int flag = 1;
        if (len == 1) return strs[0];
        
        while (flag){
            for (int i = 1; i < len; i++){
                if (strs[i] == "" || strs[i-1] == "" || strs[i][charind] == '\0' || strs[i-1][charind] == '\0'){
                    flag = 0;
                    break;
                }
                if (strs[i][charind] != strs[i-1][charind]){
                    flag = 0;
                    break;
                }
                if (i == len - 1){
                    answer += strs[i][charind];
                    charind++;
                }
            }
        }
        
        
        return answer;
    }
};