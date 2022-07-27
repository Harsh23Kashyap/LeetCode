class Solution {
public:
    int minimumBuckets(string s) 
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='H')
            {
                if(i-1>=0 and s[i-1]=='B')
                    continue;
                else if(i+1<s.size() and s[i+1]=='.')
                    s[i+1]='B';
                else if(i-1>=0 and s[i-1]=='.')
                    s[i-1]='B';
                else
                    return -1;
            }
        }
        int c=0;
        for(char ch:s)
            if(ch=='B')
                c++;
        return c;
        
    }
};