class Solution {
public:
    int getMaximumGenerated(int n) 
    {
        if(n<1)
            return 0;
        if(n<=2)
            return 1;
        vector<int> ans={0,1};
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
                ans.push_back(ans[i/2]);
            else
                 ans.push_back(ans[i/2]+ans[i/2 +1]);
        }
        return *max_element(ans.begin(),ans.end());
        
    }
};