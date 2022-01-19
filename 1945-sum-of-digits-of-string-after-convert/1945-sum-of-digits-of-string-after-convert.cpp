class Solution {
public:
    int getLucky(string s, int k) 
    {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++)
            ans=ans+to_string(s[i]-'a'+1);
        cout<<ans<<endl;
        int temp=0;
        while(k--)
        {
            for(int i=0;i<ans.length();i++)
                temp+=(ans[i]-'0');
            ans=to_string(temp);
            temp=0;
        }
        int fans=stoi(ans);
        return fans;
    }
};