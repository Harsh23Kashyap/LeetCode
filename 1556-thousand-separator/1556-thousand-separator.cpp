class Solution {
public:
    string substring(string s,int i, int j)
    {
        string ans="";
        for(int k=i;k<j;k++)
            ans+=s[k];
        
        return ans;
    }
    string thousandSeparator(int n) 
    {
        string num=to_string(n);
        string ans="";
        while(num.length()>3)
        {
            string temp=substring(num,num.length()-3,num.length());
            //cout<<temp<<endl;
            ans=temp+"."+ans;
            //cout<<ans<<" - "<<endl;
            num=substring(num,0,num.length()-3);
        }
        //cout<<substring(num,0,num.length())<<endl;
        ans=substring(num,0,num.length())+"."+ans;
        //cout<<ans<<endl;
        return substring(ans,0,ans.length()-1);
    }
};