class Solution {
public:
    
    int count = 0;
    
    string kthPermutation(vector<int> visited, int n, int k, string potAns){
        if(potAns.size() == n){
            count++;
            return potAns;
        }
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                visited[i] = 1;
                char num = '0' + i;
                potAns.push_back(num);
                string ans = kthPermutation(visited, n, k, potAns);                
                if(count == k) return ans;
                potAns.pop_back();
                visited[i] = 0;
            }
        }
        
        return "";
    }
    
    int fact(int n){
        int ans = 1;
        
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
            
        return ans;
    }
    
    string getPermutation(int n, int k) {
        vector<int> visited(n+1, 0);
        string ans = "";
        
        int x = n-1;
        int factx = fact(x);
        
        while(k != 0){
            int pos = ceil((float)k/factx);
            cout<<"\n"<<pos<<" "<<k<<" "<<factx<<" \n";
            for(int i = 1; i <= n; i++){
                if(!visited[i]){
                    pos--;
                    if(pos == 0){
                        visited[i] = 1;
                        ans += ('0' + i);
                        cout<<ans<<" ";
                        break;
                    }
                }
            }
            
            k = k%factx;
            x--;
            factx = fact(x);
        }
        
        cout<<"\n";
        
        for(int i = n; i > 0; i--){
            if(!visited[i]){
                ans += ('0' + i);
                cout<<ans<<" "; 
            } 
        }
        
        cout<<"\n";
        
        return ans;
        
        // return kthPermutation(visited, n, k, "");
    }
};