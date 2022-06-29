class Solution {
public:
   unordered_map<int,bool> mem;
    unordered_set<string> myset;//dictionary
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        
       for(auto str: wordDict)
            myset.insert(str);
        //cout<<"runs"<<endl;
        return pass(s,0);
    
    }
    bool pass(string s,int i)
    {
        if(i==s.size())
            return true;
        if(mem.count(i))  
            return mem[i];
        for(int j=i;j<s.size();j++)
        {
            string sub=s.substr(i,j-i+1);
            if(myset.count(s.substr(i,j-i+1)) and pass(s,j+1))
                return mem[i] = true;
               
            }
         return mem[i] = false;
        }
       
};