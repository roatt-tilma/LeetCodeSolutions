class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 1, d = 0, l = 0, u = 0;
        int i = 0, j = 0;
        int count = m*n;
        vector<int> ans;
        
        while(count){
            if (r){
                if (j != n && matrix[i][j] != 101){
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                    j++;
                    continue;
                }
                
                j--;
                i++;
                r = 0;
                d = 1;    
            }
            
            if (d){
                if (i != m && matrix[i][j] != 101){
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                    i++;
                    continue;
                }
                
                i--;
                j--;
                d = 0;
                l = 1;
            }
            
            if (l){
                if (j != -1 && matrix[i][j] != 101){
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                    j--;
                    continue;
                }
                
                j++;
                i--;
                l = 0;
                u = 1;
            }
            
            if (u){
                if (i != -1 && matrix[i][j] != 101){
                    ans.push_back(matrix[i][j]);
                    matrix[i][j] = 101;
                    i--;
                    continue;
                } 
                
                i++;
                j++;
                u = 0;
                r = 1;
            }
            
            count--;
        }
        return ans;
    }
};