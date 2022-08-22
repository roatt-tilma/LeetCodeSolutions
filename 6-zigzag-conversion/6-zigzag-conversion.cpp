class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> strs(numRows);
        
        if(numRows <= 1) return s;
        
        // 1 -> down, -1 -> up 
        int dir = 1;
        int row = 0;
        
        // PAYPALISHIRING
        
        //0->P  I
        //1->A L 
        //2->YA
        //3->P
        
        for(auto i: s){
            strs[row].push_back(i);
            if(row == 0) dir = 1;
            if(row == numRows-1) dir = -1;
            row += dir;
        }
        
        s.clear();
        
        for(int i = 0; i < numRows; i++){
            for(auto j: strs[i]){
                s.push_back(j);
            }
        }
        
        return s;
        
    }
};