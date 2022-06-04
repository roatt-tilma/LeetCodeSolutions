class Solution {
public:
    
    int nonPrimes[5000000];
    //int primes[5000000];
    //int i = 0;
    
    bool isPrime(int n){
        if(n == 2 || n == 3 || n == 5){
        //    primes[i++] = n;
            return true;  
        } 
        
        if(nonPrimes[n] == 1) return false;
        
        //int x = n/3;

        //for(int j = 0; primes[j] <= x; j++){
        //    if(n%primes[j] == 0) return false;
        //    x = n/primes[j];
        //}
        
        //primes[i++] = n;
        
        //for(int j = 3; j*j < n; j++){
        //    if(n%j == 0) return false;
        //}
        return true;
    }
    
    int countPrimes(int n) {
        
        if(n == 0 || n == 1 || n == 2) return 0;
        
        int count = 0;
        
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                long j = i;
                long k = i;
                while(j<n){
                    nonPrimes[j] = 1;
                    j = i*(k++);
                    //cout<<j<<"\n";
                }
                count++;
            }
        }
        
        return count;
    }
};