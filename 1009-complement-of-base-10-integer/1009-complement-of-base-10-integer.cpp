class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n==0)
            return 1;
        int ans=0;
        int p=0;
        
        while(n)
        {
            int dig=!(n&1);
            ans= (dig<<p++) | ans;
            n=n>>1;
        }
        return ans;
        
    }
};