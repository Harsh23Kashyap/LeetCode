class Solution {
public:
    int countSubstrings(string s) 
    {
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            int l=i,r=i;
            while(l>=0 and r<s.length() and s[l]==s[r])
            {
                res++;
                l--;
                r++;
            }
            
         l=i,r=i+1;
            while(l>=0 and r<s.length() and s[l]==s[r])
            {
                res++;
                l--;
                r++;
            }
        }
        return res;
        
    }
};