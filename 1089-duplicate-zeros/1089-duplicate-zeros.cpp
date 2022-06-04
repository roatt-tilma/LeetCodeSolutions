class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        //cout<<arr[0]<<"\n";
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] == 0){
                for(int j = arr.size()-1; j > i; j--){
                    arr[j] = arr[j-1]; 
                }
                i++;
            }
        }
    }
};