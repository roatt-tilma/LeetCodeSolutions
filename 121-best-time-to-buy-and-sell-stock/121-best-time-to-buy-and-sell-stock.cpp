class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         int buyDay = prices[0];
//         int maxProfit = INT_MIN;
        
//         for(int i = 0; i < prices.size() - 1; i++){
//             if(buyDay < prices[i]) continue;
            
//             buyDay = prices[i];
//             int sellDay = prices[i];
            
//             for(int j = i+1; j < prices.size(); j++){
                
//                 if(sellDay > prices[j]) continue;
                
//                 if(maxProfit < prices[j] - buyDay){
//                     maxProfit = prices[j] - buyDay;
//                     sellDay = prices[j];
//                 }
                
//                 maxProfit = max(maxProfit, prices[j] - buyDay);
//             }
//         }
        
        int maxProfit = INT_MIN;
        int buyPrice = prices[0];
        
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] - buyPrice < 0){
                buyPrice = prices[i];
            } else if(maxProfit < prices[i] - buyPrice){
                maxProfit = prices[i] - buyPrice;
            }
        }
        
        if(maxProfit < 0) return 0;
        
        return maxProfit;
        
    }
};