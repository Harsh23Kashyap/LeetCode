class Solution {
public:
    string shortestCompletingWord(string lP, vector<string>& words) 
    {
        unordered_map<char,int> u;
        for(char ch:lP)
        {
            if(isalpha(ch))
                u[tolower(ch)]++;
        }
        string curr;
        curr.append(1000, 'a');
        for(string s:words)
        {
            unordered_map<char,int> u1;
            for(char ch:s)
            {
                if(isalpha(ch))
                    u1[tolower(ch)]++;
            }
            bool hasAll=true;
            for(auto i:u)
            {
                char check=i.first;
                if(u1.find(check)==u1.end())
                {
                    hasAll=false;
                    break;
                }
                else if(u1[check]<u[check])   
                {
                    hasAll=false;
                    break;
                }
            }
            if(hasAll)
            {
                if(s.length()<curr.length())
                    curr=s;
            }
        }
        return curr;
        
    }
};