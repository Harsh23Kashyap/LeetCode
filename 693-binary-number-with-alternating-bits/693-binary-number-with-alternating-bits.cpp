class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        if(n==1)
            return true;
        int curr=n&1;
        n=n>>1;
        while(n)
        {
            int dig=n&1;
            cout<<curr<<endl;
            cout<<dig<<endl;
            if(dig==curr)
                return false;
            else
                curr=dig;
            n=n>>1;
        }
        return true;
    }
};