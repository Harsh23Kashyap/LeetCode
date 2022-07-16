
class Solution {
public:
    
    int get(int i, unordered_map<int,int> &dp)
    {
        if(i==1)
            return 1;
        if(dp.count(i)>0)
            return dp[i];
        
        if(i&1)
            dp[i]=1+get(3*i+1,dp);
        else
            dp[i]=1+get(i/2,dp);
        
        return dp[i];
            
    }
    int getKth(int lo, int hi, int k) 
    {
        
        unordered_map<int,int> dp;
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++)
            v.push_back({get(i,dp),i});
        
        sort(v.begin(),v.end());
        return v[k-1].second;
    }
};