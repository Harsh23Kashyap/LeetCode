class Solution {
public:
    int removePalindromeSub(string s) 
    {
string ans=s;
        reverse(s.begin(),s.end());
        return s==ans?1:2;
    }
};