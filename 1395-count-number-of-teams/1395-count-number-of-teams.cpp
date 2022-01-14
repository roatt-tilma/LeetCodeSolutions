class Solution {
public:
    int getCount(vector<int>& rating, int n){
        int count = 0;
        int j,k;
        
        //for (int i = 0; i < n-2; i++){
        //    for (int j = i+1; j < n-1; j++){
        //        for (int k = j+1; k < n; k++){
        //            if (rating[i] < rating[j] && rating[j] < rating[k]) count++;
        //            else if (rating[i] > rating[j] && rating[j] > rating[k]) count++;
        //        }
        //   }
        //}
        int leftSmall;
        int rightSmall;
        int leftLarge;
        int rightLarge;
        
        for (int i = 1; i < n-1; i++){
            j = i-1;
            k = i+1;
            leftSmall = 0;
            rightSmall = 0;
            leftLarge = 0;
            rightLarge = 0;
            while(j>=0 || k<n){
                if (j>=0){
                    if(rating[j] < rating[i]) leftSmall++;
                    else leftLarge++;
                    j--;  
                } 
                if (k<n){
                    if (rating[k] < rating[i]) rightSmall++;
                    else rightLarge++;
                    k++;  
                } 
                
            }
            count += leftSmall*rightLarge + leftLarge*rightSmall;
        }
        
        
        return count;
    }
    int numTeams(vector<int>& rating) {
        return getCount(rating, rating.size());
    }
};