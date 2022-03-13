class Solution {
public:
    bool isValid(string s) {
        stack<char> b;
        for (int i=0;i<s.length();i++)
        {
            char ch= s.at(i);
            if(ch=='(' || ch=='{' || ch=='[')
                b.push(ch);
            else if(ch==')' || ch=='}' || ch==']')
            {
                if(b.size()==0)return false;
                if(ch==')' && b.top()!='(')
                    return false;
                else if(ch==']' && b.top()!='[')
                    return false;
                if(ch=='}' && b.top()!='{')
                    return false;
                b.pop();
                    
            }
        }
        if(b.size()!=0)
            return false;
        return true;
    }
};