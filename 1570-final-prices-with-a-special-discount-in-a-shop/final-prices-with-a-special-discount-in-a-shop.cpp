class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        for(int i=0;i<prices.size();i++)
        {
            int sz=0;
            for(int j=i+1;j<prices.size();j++)
            {
                if(prices[j]<=prices[i])
                {
                    sz=prices[j];
                    break;
                }
            }
            prices[i]-=sz;
        }
        return prices;
    }
};