class Solution {
public:
    
    int number_of_ones(int x){
        
        int count = 0;
        
        while(x){
            if(x%2 == 1) count++;
            x = x >> 1;
        }
        
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i < n+1; i++){
            ans.push_back(number_of_ones(i));
        }
        
        return ans;
    }
};