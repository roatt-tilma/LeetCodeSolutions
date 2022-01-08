class Solution {
public:
    int findCount(int i, int j, vector<int> nums, int num, unordered_map<int, int> countMap){
        int len = nums.size();
        int count = 0;
        long square = pow(num,2);
        long product;
        while (i >= 0 && j < len){
            product = nums[i];
            product *= nums[j];
            if (product == square){
                count += countMap[nums[i]]*countMap[nums[j]];
                i--;
                j++;
            }
            else if (product < square) j++;
            else i--;
        }
        return count;
    }
    
    int findTriplets(vector<int>& nums1, vector<int>& nums2, unordered_map<int, int> count1, unordered_map<int, int> count2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int count = 0;
        int countAsst = 0;
        int numberToSearch;
        int countOfNumberToSearch;
        int checkpointWhileSearching = 0;
        for(int i = 0; i < len1; i++){
            numberToSearch = nums1[i];
            countOfNumberToSearch = count2[numberToSearch];
            countAsst = 0;
            for(int j = checkpointWhileSearching; j < len2; j++){
                if (nums2[j] > numberToSearch){
                    checkpointWhileSearching = j;
                    countAsst += findCount(j-1, j, nums2, numberToSearch, count2);
                    break;
                }
            }
            countAsst += countOfNumberToSearch * (countOfNumberToSearch - 1) / 2;
            count += count1[numberToSearch]*countAsst;
        }
        return count;
    }      
     
    void getCount(set<int>& numset, unordered_map<int, int>& count, vector<int>& nums){
        int val;
        for(auto i:nums){
            numset.insert(i);
            count[i]++;
        }
        nums.clear();
        for (auto i:numset){
            nums.push_back(i);
        }
        numset.clear();
    }
    
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        set<int> numset1;
        set<int> numset2;
        unordered_map<int, int> count1;
        unordered_map<int, int> count2;
        
        getCount(numset1, count1, nums1);
        getCount(numset2, count2, nums2);
        
        int ans1 = findTriplets(nums1, nums2, count1, count2);
        int ans2 = findTriplets(nums2, nums1, count2, count1);
        
        return ans1 + ans2;
    }
};