class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        string answer = "";
        char temp = ' ';
        int charind = 0;
        int flag = 1;
        if (len == 1) return strs[0];
        
        while (flag){
            for (int i = 0; i < len; i++){
                if (strs[i] == "") flag = 0;
                if (i == 0){
                    temp = strs[i][charind];
                    continue;
                }
                if (!strs[i-1][charind] || strs[i][charind] != strs[i-1][charind]){
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