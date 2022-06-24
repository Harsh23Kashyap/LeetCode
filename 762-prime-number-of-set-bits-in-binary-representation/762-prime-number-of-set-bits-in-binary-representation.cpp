class Solution {
public:
    int countPrimeSetBits(int left, int right) 
    {
        int c=0;
        for(int i=left;i<=right;i++)
        {
            int cn=i;
            int cc=0;
            while(cn>0)
            {
                cc++;
                cn=cn&(cn-1);
            }
            bool prime=true;
            for(int i=2;i*i<=cc;i++)
            {
                if(cc%i==0)
                {
                    prime=false;
                    break;
                }
            }
            if(prime and cc!=1)
            {
                //cout<<i<<" "<<cc<<endl;
             c++;
            }
        }
        return c;
        
    }
};