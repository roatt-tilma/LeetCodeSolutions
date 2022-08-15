class Solution {
public:
    
    int recurse(vector<pair<int, int>>& counts, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if(m < 0 || n < 0) return -1;
        if(i >= counts.size()) return 0;
        
        if(dp[m][n][i] != -1) return dp[m][n][i];
        
        return dp[m][n][i] = max(1+recurse(counts, m - counts[i].first, n - counts[i].second, i+1, dp), recurse(counts, m, n, i+1, dp));
        
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts;
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(strs.size()+1, -1)));
        
        for(auto i: strs){
            int a = 0;
            int b = 0;
            for(auto j: i){
                if(j == '0') a++;
                else b++;
            }
            counts.push_back({a, b});
        }
        
        return recurse(counts, m, n, 0, dp);
    }
};