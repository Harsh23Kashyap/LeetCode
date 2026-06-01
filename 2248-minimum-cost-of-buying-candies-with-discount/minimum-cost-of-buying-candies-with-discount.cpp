class Solution {
public:
    int minimumCost(vector<int>& cost) 
    {
        int price=0;
        sort(cost.begin(),cost.end());
        int buffer=2;
        for(int i=cost.size()-1;i>=0;i--)
        {
            if(buffer==0) 
            {
                buffer=2;
            }
            else
            {
                buffer--;
                price+=cost[i];
            }
        }
        return price;
    }
};