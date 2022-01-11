class Solution {
public:
    bool isADigit(string s)
    {
        for (int i=0;i<s.length();i++)
        {
            if(!isdigit(s[i]))
                return false;
        }
        return true;
    }
    bool areNumbersAscending(string s) 
    {
        int prev=INT_MIN;
        stringstream words(s);
        string temp="";
        while(words>>temp)
        {
            
            if(isADigit(temp))
               {
                    int curr=stoi(temp);
                    if(curr<=prev)
                   {
                       //prev=s[i]-'0';
                       return false;
                   }
                    else
                        prev=curr;
               }
        }
        return true;
    }
};