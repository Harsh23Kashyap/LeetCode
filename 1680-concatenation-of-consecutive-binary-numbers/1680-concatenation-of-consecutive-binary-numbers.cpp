class Solution {
public: 
    
    int concatenatedBinary(int n) 
    {
        int m=1e9+7;
        long long curr=0;
        for(int i=1;i<=n;i++)
        {
            int dig=(int)(log2(i))+1;
            curr=(((curr<<dig)%m) + i)%m;
            //cout<<curr<<endl;
        }
        return curr;
        
    }
};