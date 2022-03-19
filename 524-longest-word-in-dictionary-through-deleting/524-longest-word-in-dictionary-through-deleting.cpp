class Solution {
public:
    static bool cmp(string a, string b)
    {
        if(a.length()>b.length())
            return true;
        else if(a.length()==b.length())
        {
            if(a<b)
                return true;
            return false;
        }
        return false;
        
    }
    string findLongestWord(string s, vector<string>& dictionary) 
    {
        
        sort(dictionary.begin(),dictionary.end(),cmp);
        string ans="";
        for( string i:dictionary)
        {
            string temp=i;
            bool corr=true;
            int k=0;
            for(int j=0;j<s.length();j++)
            {
                if(k!=i.length() and s[j]==i[k])
                    k++;
            }
            if(k==i.length())
            {
                if(i.length()>ans.length())
                        ans=temp;
            
            }
        }
        return ans;
    }
};