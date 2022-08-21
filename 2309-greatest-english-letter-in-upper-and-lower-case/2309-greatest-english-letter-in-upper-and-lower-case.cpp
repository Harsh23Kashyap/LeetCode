class Solution {
public:
    string greatestLetter(string s) 
    {
        for(char ch='Z';ch>='A';ch--)
        {
            char temp=(char)(ch+32);
            //cout<<temp<<endl;
            size_t found1 = s.find(ch);
            size_t found2 = s.find(temp);
            if(found1!=string::npos and found2!=string::npos)
            {
                string ans="";
                ans+=ch;
                return ans;
            }
        }
        return "";
        
    }
};