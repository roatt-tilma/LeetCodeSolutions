class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> strMapA;
        unordered_map<string, char> strMapB;
        s += "1";
        string temp = "";
        int flag = 1;
        int count = 0;
        int i = 0;
        for(auto a: pattern){
            while(s[i] != ' ' && s[i] != '1'){
                temp += s[i];
                i++;
            }
            count++;
            if(s[i] == '1' && pattern.size() > count){
                return false;
            }
            if (flag){
                strMapA[a] = temp;
                strMapB[temp] = a;
                flag = 0;
                temp = "";
                i++;
                continue;
            }
            
            
            if(strMapA[a] == "" && strMapB[temp] < 'a'){
                strMapA[a] = temp;
                strMapB[temp] = a;
            }
            if (strMapB[temp] != a) return false;
            if (strMapA[a] != temp) return false;
            temp = "";
            i++;
        }
        i--;
        cout<<s[i]<<endl;
        if(s[i] != '1') return false;
        return true;
        
    }
};