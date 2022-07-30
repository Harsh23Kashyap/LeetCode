class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> a(26,0);
        for(string s:words2)
        {
            vector<int> temp(26,0);
            for(char ch:s)
                temp[ch-'a']++;
            
            for(int i=0;i<26;i++)
                a[i]=max(a[i],temp[i]);
        }
        vector<string> ans;
        for(string s:words1)
        {
            vector<int> temp(26,0);
            for(char ch:s)
                temp[ch-'a']++;
            bool b=false;
            for(int i=0;i<26;i++)
            {
                if(temp[i]<a[i])
                {
                    b=true;
                    break;
                }
            }
            if(!b)
            ans.push_back(s);
        }
        return ans;
        
    }
};