class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxP = 0;

        while(r < prices.size()){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }else{
                l = r;
            }
            r++;
        }
        return maxP;
    }
};

/*
[7, 1,  5,  3,  6,  4]
^   ^
l   r
while r is less than prices size which will be true

loop starts.

if left value is less than prices r we calculate profit right minus left value;
we store previous max  which is maxP and the calculated profit, 
usign max() we determine the max nubmer between the two(maxP and profit) store it in maxP
else we move up l and right by left becomign right and right ++ to find the values.                   

we keep doing this until no elements left.

*/
