class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0], bestSell = 0 - buyPrice;
        for (const int price : prices) {
            if (buyPrice > price) buyPrice = price;
            if (price - buyPrice >= bestSell) bestSell = price - buyPrice;
        }
        return bestSell >= 0 ? bestSell : 0;
    }
};