class Solution {
public:
    bool buddyStrings(string s1, string s2) 
    {
        if(s1.size()!=s2.size())
            return false;
        int count=0;
        int ind=-1;
        int indd=-1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i] )
            {
                count++;
                if(count>2)
                    return false;
                if(ind==-1)
                    ind=i;
                else if(indd==-1)
                    indd=i;
            }
        }
        if(count==0)
        {
            unordered_map<char,int> u;
            for(int i=0;i<s1.size();i++)
            {
                u[s1[i]]++;
                if(u[s1[i]]%2==0)
                    return true;
            }
            return false;
        }
        if(count!=2)
            return false;
       
       if(s1[ind]==s2[indd] and s1[indd]==s2[ind])
           return true;
        return false;
        
    }
};