class Solution {
public:
    int minimumSwap(string s1, string s2) 
    {
        if(s1.size()!=s2.size())
            return -1;
        int x=0,y=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]==s2[i])
                continue;
            
            if(s1[i]=='x')
                x++;
            else
                y++;
                
        }
        if((x+y)%2!=0)
            return -1;
        
        return x/2 + y/2 + x%2 + y%2;
        
    }
};