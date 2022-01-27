//#define ll long long 
class Solution {
public:
    int numDifferentIntegers(string word) 
    {
        unordered_map<string,int> u;
        //string temp="";
        for(int i=0;i<word.length();i++)
        {
            if(isdigit(word[i]))
            {
                string ans="";
                while(isdigit(word[i]) and word[i]=='0')    
                    i++;
                while(isdigit(word[i]))
                    ans=ans+(word[i++]);
                u[ans]++;
            }
        }
        
        return u.size();
    }
};