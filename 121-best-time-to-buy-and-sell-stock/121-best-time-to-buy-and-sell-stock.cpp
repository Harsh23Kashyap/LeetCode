class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxxx=0;
        int minnn=INT_MAX;
        for (int i=0;i<prices.size();i++)
        {
            minnn=min(prices[i],minnn);
            maxxx=max(prices[i]-minnn,maxxx);
        }
        return maxxx;
    }
};