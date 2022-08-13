class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int i = 0;
        int ans = 0;
        
        while(truckSize > 0 && i < boxTypes.size()){
            if(boxTypes[i][0] <= truckSize){
                ans += boxTypes[i][0] * boxTypes[i][1];
            } else {
                ans += truckSize * boxTypes[i][1];
            }
            
            truckSize -= boxTypes[i][0];
            i++;
        }
        
        return ans;
    }
};