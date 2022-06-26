class Solution {
public:
    int maxPower(string s) 
    {
        int c=1,maxi=1;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                c++;
            }
            else
            {
                maxi=max(c,maxi);
                c=1;
               
            }
        }
          maxi=max(c,maxi);
        return maxi;
        
    }
};