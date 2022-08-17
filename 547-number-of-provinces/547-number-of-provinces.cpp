class Solution {
public:
    
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int curr){
        visited[curr] = 1;
        
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i] && isConnected[curr][i]){
                dfs(isConnected, visited, i);
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n, 0);
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(isConnected, visited, i);
            }
        }
        
        return count;
    }
};