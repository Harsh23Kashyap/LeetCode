class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        int low=0;
        int high=s.length();
        vector<int> v;
        for(char ch:s)
        {
            if(ch=='I')
                v.push_back(low++);
            else
                v.push_back(high--);
        }
        v.push_back(high--);
        return v;
    }
};