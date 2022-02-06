class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if(num==0) return 0;
        string s=to_string(num);
        if(num>0)
        {
            sort(s.begin(),s.end());
            int oneind=1;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]!='0')
                {
                    oneind=i;
                    break;
                }
            }
            string ans=s[oneind]+s.substr(0,oneind)+s.substr(oneind+1);
            return stol(ans);
        }
        s=s.substr(1);
         sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        string ans='-'+s;
        return stol(ans);
        
    }
};