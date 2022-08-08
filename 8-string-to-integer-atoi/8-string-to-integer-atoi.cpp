class Solution {
public:
    int myAtoi(string s) {
        int st = -1;
        int end = -1;
        int sign = -1;
        
        long long ans = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ' && sign == -1) continue;
            if(s[i] == '-' && sign == -1){
                sign = 0;
                continue;
            }
            if(s[i] == '+' && sign == -1){
                sign = 1;
                continue;
            }
            
            if(s[i] <= '9' && s[i] >= '0' && st == -1){
                if(sign == -1) sign = 1;
                st = i;
                end = i;
                continue;
            }
            
            if(s[i] == ' ' || s[i] == '-' || s[i] == '+' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '.') break;
            
            end = i;
        }
        
        
        if(st != -1){
            string str = s.substr(st, end-st+1);
            int cnt = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == '0' && cnt == 0) continue;
                ans = (ans*10 + (str[i] - '0'));
                if(cnt++ > 12) break;
            }

            if(sign == 0) ans *= -1;
            
            if(ans < -2147483648) ans = -2147483648;
            else if(ans > 2147483647) ans = 2147483647;
        }
        
        return ans;
    }
};