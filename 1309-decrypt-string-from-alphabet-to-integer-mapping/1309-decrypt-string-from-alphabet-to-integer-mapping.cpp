class Solution {
public:
    string freqAlphabets(string s) 
    {
        string ans="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='#')
            {
                string a=s.substr(i-2,2);
                //cout<<a<<endl;
                char num=char(stoi(a)+96);
                ans=num+ans;
                i-=2;
            }
            else
            {
                string a=s.substr(i,1);
                //cout<<a<<endl;
                char num=char(stoi(a)+96);
                ans=num+ans;
            }
        }
        return ans;
            
        
    }
};