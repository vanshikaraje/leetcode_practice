class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

            if(prices[i] < minprice) {
                minprice = prices[i];
            }

            int profit = prices[i] - minprice;

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};