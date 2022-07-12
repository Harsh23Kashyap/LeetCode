class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char,int> u;
        u['I']=1;
        u['V']=5;
        u['X']=10;
        u['L']=50;
        u['C']=100;
        u['D']=500;
        u['M']=1000;
        
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size())
            {
                int num1=u[s[i]];
                int num2=u[s[i+1]];
                
                if(num1<num2)
                    ans-=num1;
                else
                    ans+=num1;
            }
            if(i==s.size()-1)
                ans+=u[s[i]];
        }
        return ans;
        
    }
};