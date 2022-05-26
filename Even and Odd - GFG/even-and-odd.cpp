// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int arr[], int N) {
        int even = 0;
        int odd = 1;
        int temp;
        int flag = 0;
        while(true){
            
            while(arr[even]%2 == 0 && flag == 0){
              if (even >= N){
                  flag = 1;
                  break;
              } 
              even += 2;  
            } 
            
            if(flag) break;
            
            while(arr[odd]%2 == 1){
                if (odd >= N){
                  flag = 1;
                  break;
                } 
                odd += 2;    
            } 
            
            if(flag) break;
            
            temp = arr[even];
            arr[even] = arr[odd];
            arr[odd] = temp;
        }
        
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends