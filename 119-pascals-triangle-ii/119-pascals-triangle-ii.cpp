class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> ans;
        vector<int> lastRow;
        
        ans.push_back(1);
        lastRow = ans;
        
        if(rowIndex != 0){
            
            for(int i = 1; i <= rowIndex; i++){
                ans.clear();
                
                ans.push_back(1);
                
                for(int j = 0; j < lastRow.size()-1; j++){
                    ans.push_back(lastRow[j] + lastRow[j+1]);       
                }
                
                ans.push_back(1);
                
                lastRow = ans;
            }
            
        }
        
        
        return ans;
    }
};