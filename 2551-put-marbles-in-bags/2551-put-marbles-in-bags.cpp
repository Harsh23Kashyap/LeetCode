class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> ans;
        for(int i=0;i<weights.size()-1;i++)
        {
           ans.push_back(weights[i]+weights[i+1]);
        }
        sort(ans.begin(),ans.end());
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++)
        {
            mini+=ans[i];
            maxi+=ans[ans.size()-1-i];
        }
        return maxi-mini;
    }
};