class Solution {
public:
    //string reverse()
    string reverse(string s)
    {
        for(int i=0;i<s.length()/2;i++)
        {
            char a=s[i];
            s[i]=s[s.length()-i-1];
            s[s.length()-i-1]=a;
        }
        return s;
    }
    string wordExtract(string s, int start, int end)
    {
        string temp="";
        for (int j=start;j<end;j++)
            temp=temp+s[j];
        return temp;
    }
    string reverseWords(string s) 
    {
        if(s.length()==1) return s;
        s=s+" ";
        int start=0;
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                cout<<start<<","<<i<<endl;
                string word=wordExtract(s,start,i);
                cout<<word<<endl;
                temp=temp+reverse(word)+" ";
                start=i+1;
            }
            
        }
        return temp.substr(0,temp.length()-1);
    }
};