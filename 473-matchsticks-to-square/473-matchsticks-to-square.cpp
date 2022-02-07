class Solution {
public:
    int totalone=0;
    bool check(vector<int>& ans)
    {
        if(ans[0]==ans[1] and ans[1]==ans[2] and ans[2]==ans[3])
        {
            //cout<<ans[0]<<","<<ans[1]<<" , "<<ans[2]<<" , "<<ans[3]<<endl;
            return true;
        }
        //cout<<ans[0]<<","<<ans[1]<<" , "<<ans[2]<<" , "<<ans[3]<<endl;
        return false;
    }
    bool sidesval(vector<int>& m,vector<int>& s,int i)
    {
        if(i==m.size())
            return check(s);
        //bool ans=false;
        for(int j=0;j<4;j++)
        {
            if(s[j]+m[i]<=totalone)
            {
                s[j]+=m[i];
                //cout<<j<<" - i-"<<s[j]<<endl;
                if(sidesval(m,s,i+1))
                    return true;
                s[j]-=m[i];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) 
    {
        totalone=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(totalone%4!=0)
            return false;
        totalone/=4;
        //cout<<totalalone<<endl;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        vector<int> sides(4,0);
        return sidesval(matchsticks,sides,0);
        
    }
};