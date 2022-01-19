class Solution {
public:
    const int MOD = 1e9+7, N = 50;
    long long int dp[55][55][55];
    
    long long int f(int m, int n, int r, int c, int remMov){
        if (remMov < 0){
            return 0;
        }
        
        if (r<0 || r>m-1 || c<0 || c>n-1) return 1;
        
        if(dp[r][c][remMov] != -1){
            return dp[r][c][remMov];
        }
        
        dp[r][c][remMov] = f(m,n,r-1,c,remMov-1)%MOD + f(m,n,r,c-1,remMov-1)%MOD + f(m,n,r+1,c,remMov-1)%MOD + f(m,n,r,c+1,remMov-1)%MOD;
        
        return dp[r][c][remMov]%MOD;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return f(m, n, startRow, startColumn, maxMove);
    }
};