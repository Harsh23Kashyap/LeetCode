class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) 
    {
        s=s+" ";
        vector<vector<int>> v;
        if(s.length()<3) return v;
        int i=0,j=1;
        while( i<s.length() && j<s.length())
        {
            if(s[i]==s[j])
            {
                j++;
            }
            else
            {
                if(j-i>=3)
                    v.push_back({i,j-1});
                i=j;
            }
        }
        return v;
        
    }
};