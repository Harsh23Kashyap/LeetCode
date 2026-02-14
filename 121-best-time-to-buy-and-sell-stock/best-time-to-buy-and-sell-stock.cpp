class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int profit=0;
        for(auto it:prices)
        {
            profit=max(profit,it-mini);
            mini=min(mini,it);
        }
        return profit;
    }
};