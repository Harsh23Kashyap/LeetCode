class Solution {
public:
    int myAtoi(string s) 
    {
        int ind=0,res=0,sign=1;
        while(ind<s.size() and s[ind]==' ')
            ind++;
        
        if(ind<s.size())
        {
            if(s[ind]=='-')
            {
                sign=-1;
                ind++;
            }
            else if(s[ind]=='+')
            {
                sign=1;
                ind++;
            }
            
        }
        while(ind<s.size() and isdigit(s[ind]))
        {
            int dig=s[ind]-'0';
            
            if(res>INT_MAX/10 or (res==INT_MAX/10 and dig>INT_MAX%10))
                return sign==1?INT_MAX:INT_MIN;
            
            res=res*10+dig;
            ind++;
        }
        
        return sign*res;
    }
};