class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount==0)
            return 0;
        sort(coins.begin(),coins.end());
        vector<int> v(amount+1,amount+1);
        v[0]=0;
        for(int c=0;c<coins.size();c++)
        {
            for(int j=coins[c];j<=amount;j++)
            {
                v[j]=min(v[j],v[j-coins[c]]+1);
            }
        }
        
        // for(int i=0;i<v.size();i++)
        //     cout<<i<< " - "<< v[i]<<endl;
        if(v[amount]>amount)
            return -1;
        
        return v[amount];
    }
};