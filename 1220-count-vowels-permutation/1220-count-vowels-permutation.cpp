
class Solution {
public:
    int m=1e9 +7;
    int countVowelPermutation(int n) 
    {
        long long a=1,e=1,i=1,o=1,u=1;
        long long ca=0,ce=0,ci=0,co=0,cu=0;
        for(int in=2;in<=n;in++)
        {
            ca=a,ce=e,ci=i,co=o,cu=u;
            
            a=(ce)%m;
            
            e=(ca+ci)%m;
            
            
            i=(ca+ce+co+cu)%m;
           
            o=(ci+cu)%m;
            
            u=ca%m;
            
        }
        
        
        
       
        
        return (a+e+i+o+u)%m;
    }
};