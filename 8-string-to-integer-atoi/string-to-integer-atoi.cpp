class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0)
            return 0;
        int i=0;
        while(i<s.size() and s[i++]==' ');
        i--;
        
        int ans=0;
        int sign=1;
        if(s[i]>='0' and s[i]<='9')
            sign=1;
        else 
        {
            if(s[i]=='+')
            {
                sign=1;
                i++;
            }
            else if(s[i]=='-')
            {
                sign=-1;
            i++;
            }
        }
        // cout<<ans<<" "<<sign<<endl;
        // cout<<INT_MAX<<" "<<INT_MIN<<endl;
        while(i<s.size())
        {
            // cout<<i<<endl;
            if(not(s[i]>='0' and s[i]<='9'))
                break;
            if(ans>INT_MAX/10 or (ans==INT_MAX/10 and (s[i]-'0')>INT_MAX%10))
                return sign==1?INT_MAX:INT_MIN;
            
            ans=ans*10+(s[i]-'0');
            // cout<<ans<<endl;
            i++;
        }
        
        
        return ans*sign;
        
        
        
        
        
        
        
            
        
    }
};