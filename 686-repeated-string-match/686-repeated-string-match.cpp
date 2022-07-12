class Solution {
public:
    bool check(string a,string b)
    {
        for(int i=0;i+b.size()<=a.size();i++)
        {
            if(a.substr(i,b.size())==b)
                return true;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) 
    {
        int n=a.size(),m=b.size();
        string temp=a;
        int ans=1;
        while(a.size()<b.size())
        {
            ans++;
            a+=temp;
        }
        if(check(a,b))
            return ans;
        if(check(a+temp,b))
            return ans+1;
        
        return -1;
    }
};