class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr(encoded.size()+1);
        
        arr[0] = first;
        
        int i = 1;
        
        for(auto ele: encoded){
            arr[i] = arr[i-1] ^ ele;
            i++;
        }
        
        return arr;
    }
};