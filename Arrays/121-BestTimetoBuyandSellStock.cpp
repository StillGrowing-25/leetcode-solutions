class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int maxP=0;
        for(int i = 1, a = prices[0]; i<prices.size(); i++){
            a = min(prices[i],a);
            maxP = max(maxP,prices[i]-a);
        }
        return maxP;
    }
};
