class Solution {
public:
    string truncateSentence(string s, int k) 
    {
        
        stringstream ssr(s);
        string temp;
        string ans="";

        while(ssr>>temp)
        {
            k--;
            if(k==0)
            {
                ans+=temp;
                break;
            }
            else
                ans+=temp+" ";
        }
        return ans;
        
    }
};