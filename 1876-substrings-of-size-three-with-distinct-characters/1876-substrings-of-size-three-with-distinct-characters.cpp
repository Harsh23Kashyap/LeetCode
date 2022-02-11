class Solution {
public:
    int countGoodSubstrings(string s) 
    {
        if(s.length()<3)
            return 0;
        unordered_map<int,int> u;
        for(int i=0;i<3;i++)
            u[s[i]]++;
        
        int count=0;
        if(u[s[0]]==1 and u[s[1]]==1 and u[s[2]]==1)
            count++; 
        for(int i=0;i<s.length()-3;i++)
        {
            u[s[i]]--;
            u[s[i+3]]++;
            if(u[s[i+1]]==1 and u[s[i+2]]==1 and u[s[i+3]]==1)
                count++;
        }
        return count;
            
        
    }
};