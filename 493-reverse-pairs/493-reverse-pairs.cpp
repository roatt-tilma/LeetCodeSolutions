class Solution {
public:
    
    int merge(vector<int>& nums, int l, int mid, int r){
        
        int count = 0;
        
        int sizeOne = mid - l + 1;
        int sizeTwo = r - mid;
        
        int* arrOne = new int[sizeOne];
        int* arrTwo = new int[sizeTwo];
        
        for(int i = 0; i < sizeOne; i++) arrOne[i] = nums[l+i];
        for(int i = 0; i < sizeTwo; i++) arrTwo[i] = nums[mid+1+i];
        
        int indexOne = 0;
        int indexTwo = 0;
        
        int indexMerge = l;
        
        for(int i = 0; i < sizeOne; i++){
            while(indexTwo < sizeTwo && arrOne[i] > (long long)((long long)arrTwo[indexTwo] + (long long) arrTwo[indexTwo])){
                indexTwo++;
            }
            
            count += indexTwo;
        }
        
        indexTwo = 0;
        
        while(indexTwo < sizeTwo && indexOne < sizeOne){
            if(arrOne[indexOne] < arrTwo[indexTwo]){
                nums[indexMerge++] = arrOne[indexOne++];
            }
            else{
                nums[indexMerge++] = arrTwo[indexTwo++];
            }
        }
        
        while(indexOne < sizeOne){
            nums[indexMerge++] = arrOne[indexOne++];
        }
        
        while(indexTwo < sizeTwo){
            nums[indexMerge++] = arrTwo[indexTwo++];
        }
        
        delete[] arrOne;
        delete[] arrTwo;
        
        return count;
    }
    
    int mergeSort(vector<int>& nums, int l, int r){
        
        int mid, count = 0;
        
        if(r > l){

            mid = (l+r)/2;

            count += mergeSort(nums, l, mid);
            count += mergeSort(nums, mid+1, r);

            count += merge(nums, l, mid, r);
        }
        
        return count;
    }
    
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};