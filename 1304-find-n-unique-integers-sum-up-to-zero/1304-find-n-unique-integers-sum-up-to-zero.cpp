class Solution {
public:
    vector<int> sumZero(int n) 
    {
        vector<int> v;
        for(int i=0;i<n-1;i++)
        {
            v.push_back(i+1);
        }
        v.push_back(-(n*(n-1))/2);
        return v;
    }
};