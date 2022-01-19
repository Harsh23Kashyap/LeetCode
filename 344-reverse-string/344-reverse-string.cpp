class Solution {
public:
    void reverse(vector<char>& s, int n, int i)
    {
        if(i+1==n)
        {
            s[i]=s[0];
            return ;
        }
        char ch= s[n-i-1];
        reverse(s,n, i+1);
        s[i]=ch;
    }
    void reverseString(vector<char>& s) 
    {
        int len=s.size();
        reverse(s, len, 0);
        
    }
};