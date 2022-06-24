class Solution {
public:
    int countLargestGroup(int n) 
    {
        unordered_map<int,int> u;
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            int cn=i;
            int sum=0;
            while(cn>0)
            {
                sum+=(cn%10);
                cn/=10;
            }
            if(u.find(sum)==u.end())
                u[sum]=1;
            else
                u[sum]++;
            
            maxi=max(maxi,u[sum]);
        }
        int c=0;
        for(auto it:u)
        {
            if(it.second==maxi)
                c++;
        }
        return c;
        
    }
};