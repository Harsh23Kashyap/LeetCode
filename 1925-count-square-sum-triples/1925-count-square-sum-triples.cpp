class Solution {
public:
    int countTriples(int n) 
    {
        int count=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int num=i*i+j*j;
                //cout<<i<<" + "<<j<<" = "<<num<<endl;
                int a= sqrt(num);
                if(a<=n)
                {
                    //cout<<"runs outer"<<endl;
                    if(a*a==num)
                    {
                        //cout<<"runs"<<endl;
                        count++;
                    }
                }
                else
                    break;
            }
        }
        return count;
        
    }
};