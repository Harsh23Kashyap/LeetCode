class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        vector<vector<int>> v; 
        for(int i=0;i<st.size();i++)
            v.push_back({st[i],et[i],p[i]});
        int n = v.size();
        vector<int> dp(n + 1, 0);
        sort(v.begin(),v.end());
        vector<int> starts;
        for(int i=0;i<v.size();i++)
            starts.push_back(v[i][0]);
             
        for(int i=n-1;i>=0;i--){
            auto it=v[i];
            //now we will look for dp[i+1] and combination of curr profit and profit beyond end basially
            int skip=dp[i+1];
            int other=v[i][2];
            //upper bound to find next element greate rthn e
            auto nex=upper_bound(starts.begin(),starts.end(),v[i][1]-1);
            if(nex!=starts.end())
            {
                int idx=nex-starts.begin();
                other+=dp[idx];
            }
            
            dp[i]=max(skip,other);


        }
        return dp[0];
    }
};