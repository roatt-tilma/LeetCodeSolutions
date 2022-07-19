class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        vector<int> row;
        
        row.push_back(1);
        
        ans.push_back(row);
        
        
        for(int i = 1; i < numRows; i++){
            row.clear();
            vector<int> lastRow = ans[i-1];
            
            row.push_back(1);
            
            for(int j = 0; j < lastRow.size() - 1; j++){
                int ele = lastRow[j] + lastRow[j+1];
                row.push_back(ele);
            }
            
            row.push_back(1);
            
            ans.push_back(row);
        }
        
        return ans;
    }
};