class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> v;
        unordered_map<string,int> u;
        if(s.length()<10)
            return v;
        for(int i=0;i<=s.length()-10;i++)
        {
            //cout<<s.substr(i,10)<<endl;
            cout<<i<<" and "<<i+10<<endl;
            u[s.substr(i,10)]++;
        }
        
        for(auto i:u)
        {
            cout<<i.first<<endl;
            if(i.second>1)
                v.push_back(i.first);
        }
        return v;
    }
};