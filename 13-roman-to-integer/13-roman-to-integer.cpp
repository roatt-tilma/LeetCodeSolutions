#include <string.h>
#include <iostream>

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> Dev{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int sum = Dev[s.back()];
        
        for(int i = s.size() - 2; i >= 0; i--){
            if(Dev[s[i]] < Dev[s[i+1]]){
                sum -= Dev[s[i]];
            } else if (Dev[s[i]] >= Dev[s[i+1]]){
                sum += Dev[s[i]];
            }
        }
        
        return sum;
    }
};