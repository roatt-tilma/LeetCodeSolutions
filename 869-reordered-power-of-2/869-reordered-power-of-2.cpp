class Solution {
public:
    
    int getSortedNum(int n){
        unordered_map<int, int> mp;
        
        while(n){
            mp[n%10]++;
            n = n / 10;
        }
        
        int ans = 0;
        
        for(int i = 1; i < 10; i++){
            for(int j = 0 ; j < mp[i]; j++){
                ans = ans*10 + i;
            }
        }
        
        ans = ans*pow(10, mp[0]);
        
        return ans;
    }
    
    vector<int> getSortedPowersOf2(){
        int i = 0;
        int p = pow(2, i);
        
        vector<int> sortedPowerOf2;
        
        while(p <= 1e9){
            
            int num = getSortedNum(p);
            
            sortedPowerOf2.push_back(num);
            
            p = pow(2, ++i);
        }
        
        return sortedPowerOf2;
    }
    
    bool reorderedPowerOf2(int n) {
        vector<int> sortedPowersOf2 = getSortedPowersOf2();
        
        n = getSortedNum(n);
        
        for(auto num: sortedPowersOf2){
            if(num == n) return true;
        }
        
        return false;
    }
};