class Solution {
public:
    string recur(string s, int n)
    {
        if(n==0)
            return s;
        //cout<<s<<endl;
        string rev=s;
        for(int i=0;i<rev.length();i++)
            rev[i]=(rev[i]=='0')?'1':'0';
        
        reverse(rev.begin(),rev.end());
        return recur(s+'1'+rev,n-1);
    }
    char findKthBit(int n, int k) 
    {
        string s="0";
        if(n==1 || k==1)
            return '0';
        string ans=recur(s,n-1);
        //cout<<ans<<endl;
        return ans[k-1];
    }
};