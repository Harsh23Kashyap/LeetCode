class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        if(num=="0" || num.length()==k) return "0";
        stack<char> s;
        
        s.push(num[0]);
        
        for(int i=1;i<num.length();i++)
        {
            char curr=num[i];
            while(!s.empty() and s.top()>curr and k>0)
            {
                k--;
                s.pop();
            }
            if(s.empty() and curr=='0') continue;
            else
                s.push(curr);
        }
        
        string ans="";
        while(!s.empty() and k--)
            s.pop();
        while(!s.empty())
        {
            ans=s.top()+ans;
            s.pop();
        }
        if(ans=="") return "0";
        return ans;
    }
};


