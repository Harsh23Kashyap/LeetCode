class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
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
            return true;
        if(count>2 or count==1)
            return false;
        //cout<<ind<<" "<<indd<<". "<<s1[indd]<<","<<s2[ind]<<endl;
       if(s1[ind]==s2[indd] and s1[indd]==s2[ind])
           return true;
        return false;
        
    }
};