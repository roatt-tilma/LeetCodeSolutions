class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        
        vector<int> ans(2, -1);
        
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                ans[0] = l+1;
                ans[1] = r+1;
                break;
            }
            if(numbers[l] + numbers[r] < target){
                l++;
            }
            if(numbers[l] + numbers[r] > target){
                r--;
            }
        }
        
        return ans;
    }
};