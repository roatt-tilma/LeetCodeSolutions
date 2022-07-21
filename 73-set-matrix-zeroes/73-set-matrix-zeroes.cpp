class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<int, int> rowZero;
        map<int, int> colZero;
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    colZero[j] = 1;
                    rowZero[i] = 1;
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            if(rowZero[i] == 1){
                for(int j = 0; j < matrix[i].size(); j++){
                    matrix[i][j] = 0;
                }
            }    
            else{
                for(int j = 0; j < matrix[i].size(); j++){
                    if(colZero[j] == 1){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};