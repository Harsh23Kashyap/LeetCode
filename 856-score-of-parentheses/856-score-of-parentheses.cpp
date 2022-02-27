class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int total=0;
        int bal=0;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                bal++;
            }
            else
            {
                bal--;
                if(s[i-1]=='(')
                    total+=(1<<bal);
                    
                
            }
        }
        return total;
        
    }
};