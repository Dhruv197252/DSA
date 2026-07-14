class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit=0;
        int currentMinBuy = prices[0];
        for(int i =1;i<n;i++){
            if(prices[i]>currentMinBuy){
                profit=max(profit, prices[i]-currentMinBuy);
            }
            currentMinBuy=min(currentMinBuy, prices[i]);
        }
        return profit;
    }
};