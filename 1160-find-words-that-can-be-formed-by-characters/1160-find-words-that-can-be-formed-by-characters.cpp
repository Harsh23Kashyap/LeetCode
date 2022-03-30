class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        unordered_map<int,int> u;
        for(char c:chars)
            u[c]++;
        int count=0;
        for(string s:words)
        {
            unordered_map<int,int> u1;
            for(char c:s)
                u1[c]++;
            bool see=true;
            for(auto it:u1)
            {
                if(u.find(it.first)==u.end() or u[it.first]<it.second)
                {
                    see=false;
                    break;
                }
            }
            if(see)
                count+=s.length();
        }
        return count;
        
    }
};