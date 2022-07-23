class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int buyPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - buyPrice < 0){
                buyPrice = prices[i];
            } else if(maxProfit < prices[i] - buyPrice){
                maxProfit = prices[i] - buyPrice;
            }
        }
        
        return maxProfit;
        
    }
};