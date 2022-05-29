class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
       
        vector<int> v(words.size(),0);
        for(int i=0;i<words.size();i++)
        {
            int te=0;
            for(int j=0;j<words[i].size();j++)
            {
                te= te|(1<<(words[i][j]-'a'));
            }
            v[i]=te;
        }
        int len=INT_MIN;
        for(int i=0;i<words.size()-1;i++)
        {
            
            for(int j=i+1;j<words.size();j++)
            {
                if((v[j]&v[i]) == 0)
                {
                   len = max(len, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        if(len==INT_MIN)
            return 0;
        return len;
    }
};