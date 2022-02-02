class Solution {
public:
    bool isAnagram(unordered_map<char,int> hashp,unordered_map<char,int> hashst)
    {
            for(auto i:hashp)
            {
                //cout<<i.first<<endl;
                if(hashst[i.first]!=i.second)
                    return false;
            }
            return true;
    }
    vector<int> findAnagrams(string s, string p) 
    {
        int k=p.length();
        vector<int> ans;
        //return ans;
        if(s.length()<p.length())
            return ans;
        unordered_map<char,int> hashp;
        for(char ch='a';ch<='z';ch++)
            hashp[ch]=0;
        for(char c:p)
            hashp[c]++;
        
        unordered_map<char,int> hashst;
        for(char ch='a';ch<='z';ch++)
            hashst[ch]=0;
        // for(auto i:hashst)
        //     cout<<i.first<<" - "<<i.second;
        for(int i=0;i<k;i++)
            hashst[s[i]]++;
        
        if(isAnagram(hashp,hashst))
            ans.push_back(0);   
        
        for(int i=k;i<s.length();i++)
        {
            
            hashst[s[i-k]]--;
            hashst[s[i]]++;
            if(isAnagram(hashp,hashst))
            {
                cout<<i-k+1;
                ans.push_back(i-k+1);  
            }
                
        }
        return ans;
        
    }
};