class Solution {
public:
    string ans(string a, int& i)
    {
        string res="";
        while(i<a.length() and a[i]!=']')
        {
            //cout<<"Curr- "<<a[i]<<endl;
            if(isdigit(a[i]))
            {
                int k=0;
                //i++;
                while(i<a.length() and isdigit(a[i]))
                    {
                        k=k*10+(a[i++]-'0');

                    }
                i++;
                string r=ans(a,i);
                i++;
                while(k--)
                {
                    res=res+r;
                }
            }
            else
                res+=a[i++];
        }
        return res;
    }
    string decodeString(string s) 
    {
        int i=0;
        return ans(s,i);
    }
};