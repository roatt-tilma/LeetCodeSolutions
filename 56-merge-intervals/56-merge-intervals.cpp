class Solution {
public:
    
    static bool compareInterval(vector<int>& i1, vector<int>& i2){
        return (i1[0] < i2[0]);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        
        sort(intervals.begin(), intervals.end(), compareInterval);
        
        int flag = 0;
        
        int lBound = intervals[0][0];
        int rBound = intervals[0][1];

        
        for(int i = 1; i < n; i++){
            if(rBound >= intervals[i][0]){
                rBound = max(rBound, intervals[i][1]);
            } else {
                ans.push_back(vector<int> {lBound, rBound});
                
                lBound = intervals[i][0];
                rBound = intervals[i][1];
            }
        }
        
        ans.push_back(vector<int> {lBound, rBound});
        
        return ans;
    }
};