class Solution {
public:
    string makeEven(string s)
    {
        string t;
        for(int i=0;i<s.length()-1;i++)
            t+=s[i];
        
        return t;
            
    }

    string makeOdd(string s)
    {
        //string t;
        int i;
        for(i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='1')
                s[i]='0';
            
            else
            {
                s[i]='1';
                break;
            }
        }
        if(i<0)
            s="1"+s;
        return s;
            
    }
    int numSteps(string s) 
    {
        int c=0;
        while(s.size()>1)
        {
            if(s[s.length()-1]=='1')
                s=makeOdd(s);
            else
                s=makeEven(s);
            c++;
        }
        return c;
    }
};