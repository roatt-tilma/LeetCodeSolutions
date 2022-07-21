class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowNo = matrix.size();
        int colNo = matrix[0].size();
        
        int colFlag = 0;
        int rowFlag = 0;
        
        for(int i = 0; i < rowNo; i++){
            for(int j = 0; j < colNo; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) rowFlag = 1;
                    if(j == 0) colFlag = 1;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for(int j = 1; j < colNo; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < rowNo; i++){
                    matrix[i][j] = 0;                    
                }
            }
        }
            
        for(int i = 1; i < rowNo; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < colNo; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(rowFlag){
            for(int j = 0; j < colNo; j++){
                matrix[0][j] = 0;
            }
        }
        
        if(colFlag){
            for(int i = 0; i < rowNo; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};