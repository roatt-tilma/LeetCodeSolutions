class Solution {
public:
    
    bool isSubset(string a, unordered_map<char,int> count2){
        unordered_map<char, int> count1;
        
        for(auto i: a) count1[i]++;
        
        int flag = 1;
        
        for(auto i: count2){
            if(i.second > count1[i.first]) {
                flag = 0;
                break;
            }
        }
        
        if(flag) return true;
        return false;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> count2;
        vector<string> ans;
        
        for(auto i: words2){
            for(auto ch: i){
                int cnt = count(i.begin(), i.end(), ch);
                count2[ch] = max(count2[ch], cnt);
            }
        }
        
        for(auto i: words1){
            if(isSubset(i, count2)){
                ans.push_back(i);
            }
        }
       
        return ans;
        
    }
};