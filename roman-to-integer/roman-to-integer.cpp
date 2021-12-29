#include <string.h>
#include <iostream>

class Solution {
public:
    int romanToInt(string s) {
        
        int len = s.length();
        int ans = 0;
        
        for (int i = len-1; i >= 0; i--){            
            if (s[i] == 'M'){
                if (i != 0 && s[i-1] == 'C'){
                    ans += 1000 - 100;
                    i--;
                }
                else{
                    ans += 1000;
                }
            }
            else if (s[i] == 'D'){
                if (i != 0 && s[i-1] == 'C'){
                    ans += 500 - 100;
                    i--;
                }
                else{
                    ans += 500;
                }
            }
            else if (s[i] == 'C'){
                if (i != 0 && s[i-1] == 'X'){
                    ans += 100 - 10;
                    i--;
                }
                else{
                    ans += 100;
                }
            }
            else if (s[i] == 'L'){
                if (i != 0 && s[i-1] == 'X'){
                    ans += 50 - 10;
                    i--;
                }
                else{
                    ans += 50;
                }
            }
            else if (s[i] == 'X'){
                if (i != 0 && s[i-1] == 'I'){
                    ans += 10 - 1;
                    i--;
                }
                else{
                    ans += 10;
                }
            }
            else if (s[i] == 'V'){
                if (i != 0 && s[i-1] == 'I'){
                    ans += 5 - 1;
                    i--;
                }
                else{
                    ans += 5;
                }
            }
            else{
                ans += 1;
            }
        }
        
        
        return ans;
    }
};