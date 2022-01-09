class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> lis(len, 1);
        int maximum = 1;
        for (int i = 1; i < len; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j] && lis[j] >= lis[i]){
                    lis[i] = 1 + lis[j];
                }
            }
            if (maximum < lis[i]) maximum = lis[i];
        }
        return maximum;
    }
};