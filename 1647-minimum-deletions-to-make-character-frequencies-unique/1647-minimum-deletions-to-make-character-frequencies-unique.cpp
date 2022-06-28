class Solution {
public:
    int minDeletions(string s) 
    {
        vector<int> v(26,0);
        for(char ch:s)
            v[ch-'a']++;
        
        sort(v.begin(),v.end(),greater<int>());
        
        int del=0;
        int maxF=accumulate(v.begin(),v.end(),0);
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==0)
                break;
            if(maxF<v[i])
            {
                del+=abs(v[i]-maxF);
                v[i]=maxF;
               
            }
             maxF=max(0,v[i]-1);
            
        }
        return del;
        
    }
};