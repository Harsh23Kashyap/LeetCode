class Solution {
public:
   
string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        vector<int> sh(s.size()+1,0);
        for(int i=0;i<shifts.size();i++)
        {
            int si=shifts[i][0],ei=shifts[i][1],dir=shifts[i][2];
            dir=((dir==0)?-1:1);
            sh[si]+=dir;
            sh[ei+1]-=dir;
        }
        for(int i=1;i<sh.size();i++)
            sh[i]+=sh[i-1];
        string ans="";
        for(int i=0;i<sh.size()-1;i++)
        {
            
            char ch=s[i];
            char cr='?';
            int dir=sh[i]%26;
            // cout<<i<<" - "<<dir<<endl;
            // cout<<"Crrent-"<<ch<<endl;
            //cout<<(int)(ch+dir)<<endl;
            if((int)(ch+dir)>=97 and (int)(ch+dir)<=122)
            {
                //cout<<"runs1"<<endl;
                cr=(char)(ch+dir);
            }
            else if((int)(ch+dir)<97)
             {
                 //cout<<"runs2"<<endl;
                 dir=abs(dir);
                
                 dir=dir-(ch-'a')-1;
                 //cout<<dir<<endl;
                 cr=(char)('z'-dir);
             }
            else if((int)(ch+dir)>122)
            {
                // cout<<"runs3"<<endl;
                 
                //cout<<dir<<endl;
                dir=dir-('z'-ch)-1;
                //cout<<dir<<endl;
                cr=(char)('a'+dir);
            }
           // cout<<cr<<endl;
            ans+=cr;
        }
        return ans;
        
    }
};