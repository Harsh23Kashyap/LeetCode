class Solution {
public:
    bool check(int a)
    {
        bool rem=false;
        while(a>0)
        {
            if(a%10==0)
                return false;
            a/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) 
    {
        vector<int> ans;
        for(int i=1;i<n;i++)
        {
            int y=n-i;
            if(check(i) and check(y))
            {
                ans.push_back(i);
                ans.push_back(y);
                break;
            }
        }
        return ans;
        
    }
};