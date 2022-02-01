class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
        int exp=16;
        for(exp=16;pow(3,exp)>n;exp--);
        //cout<<exp;
        if(pow(3,exp)==n) return true;
        while(exp>=0 and n!=0)
        {
            if(pow(3,exp)<=n)
                n=n-pow(3,exp);
            cout<<n<<endl;
            exp--;
            
        }
        return n==0;
        
    }
};