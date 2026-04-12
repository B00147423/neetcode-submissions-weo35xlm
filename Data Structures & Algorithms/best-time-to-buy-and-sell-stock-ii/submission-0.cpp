class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit += (prices[i] - prices[i-1]);
                cout << "\n prices[i] "<< prices[i] << endl;
                cout << "\n -prices[i-1]"<< -prices[i-1] << endl;
            }
        }
    return profit;
    }
};
