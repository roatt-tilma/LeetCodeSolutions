class Solution {
public:
    int findCount(vector<int>& piles, int num, int index){
        int len = piles.size();
        int count = index+1;
        
        for (int i = index+1; i < len; i++){
            count += ceil(1.0*piles[i]/num);
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int count,l,r,m;
        int len = piles.size();
        for (int i = 0; i < len; i++){
            count = findCount(piles,piles[i],i); 
            cout<<count<<" "<<i<<endl;
            if (count == h) return piles[i];
            if (count < h){
                if (i == 0){
                  l = 0;
                  r = piles[i];
                } 
                else{
                    l = piles[i-1];
                    r = piles[i];
                }
                while (r-l != 1){
                    m = (r+l)/2; 
                    count = findCount(piles, m, i-1);
                    if (count == h){
                        for (int k = m; k >= l; k--){
                            count = findCount(piles,k,i-1);
                            if (count > h) return k+1;
                        }
                    }
                    if (count < h) r = m;
                    else l = m;
                }
                return r;
            }
            
        }
        
        return 0;
        
    }
};