class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        
        for(auto i: arr) mp[i]++;
        
        vector<int> vect;
        
        for(auto i: mp){
            vect.push_back(i.second);
        }
        
        sort(vect.rbegin(), vect.rend());
        
        int i = 0;
        
        for(i = 0; i < vect.size(); i++){
            if(n <= arr.size()/2) break;
            n -= vect[i];
        }
        
        return i;
    }
};