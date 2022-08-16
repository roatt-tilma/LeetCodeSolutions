class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> mp;
        
        for(int i = 0; i < s.size(); i++){
            mp[s[i]].first++;
            mp[s[i]].second = i;
        } 
        
        int ans = s.size();
        
        for(auto i: mp){
            if(i.second.first == 1){
                ans = min(ans, i.second.second);
            }
        }
        
        return ans == s.size() ? -1: ans;
    }
};