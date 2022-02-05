class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string ansS="";
        string ansT="";
        int i=s.length()-1;
        int count=0;
        while(i>=0)
        {
        
            if(s[i]=='#')
            {
                while(i>=0 and s[i]=='#' )
                {
                    //cout<<count<<" runs ";
                    count++;
                    i--;
                }
                //cout<<count;
            }
            else
            {
                if(count>0)
                {
                    count--;
                    i--;
                }
                else if(i>=0 and count==0)
                ansS=s[i--]+ansS;
            }
        }
        
        cout<<"S- "<<ansS<<endl;
        i=t.length()-1;
        count=0;
        while(i>=0)
        {
            //cout<<"i - "<<i<<endl;
            if(t[i]=='#')
            {
                //cout<<"runs";
                while(i>=0 and t[i]=='#' )
                {
                    count++;
                    i--;
                }
                //cout<<i<<" after #"<<count<<endl;
            }
            
            else
            {
                if(count>0)
                {
                    count--;
                    i--;
                }
                else if(i>=0 and count==0)
                {
                    ansT=t[i--]+ansT;
                //cout<<ansT<<" -"<<endl;
                }
            }
        }
        cout<<"T- "<<ansT<<endl;
        return ansS==ansT;
        
    }
};