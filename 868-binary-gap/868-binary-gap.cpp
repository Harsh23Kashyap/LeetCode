class Solution 
{
    public:
        int binaryGap(int n) 
        {
            int count=0,temp=0;
            int twoOne=0;
            while(n)
            {
                cout<<"Index - "<<(n&1)<<endl;
                if(n&1)
                {
                    twoOne++;
                    count=max(count,temp);
                    cout<<count<<endl;
                    temp=1;
                }
                else
                {
                    if(twoOne>=1)
                        temp++;
                }
                 n=n>>1;
            }
                if(twoOne<2) return 0;
                return count;
        }   
        
};