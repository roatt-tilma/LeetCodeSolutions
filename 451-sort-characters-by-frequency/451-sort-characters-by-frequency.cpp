class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;    
    }
    
    string frequencySort(string s) {
        
        unordered_map<char, int> frequencyMap;
        for (int i = 0; i < s.size(); i++){
            frequencyMap[s[i]]++;
        }
        vector<pair<char, int>> frequencyPair;
        for (auto& it : frequencyMap) {
            frequencyPair.push_back(it);
        }
        sort(frequencyPair.begin(), frequencyPair.end(), cmp);
        string ans = "";
        
        for (auto& it : frequencyPair) {
            for (int i = 0; i < it.second; i++){
                ans += it.first;
            }
        }
        
        return ans;
    }
};