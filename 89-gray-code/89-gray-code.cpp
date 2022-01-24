class Solution {
public:
    void backTrack(vector<int>& v , int i, int n)
    {
        if(i>n) return;
        int tobeadded=(1<<(i-1));
        for(int j=v.size()-1;j>=0;j--)
        {
            v.push_back(v[j]+tobeadded);
        }
        backTrack(v,i+1,n);
    }
    vector<int> grayCode(int n) 
    {
        vector<int>gc{0,1};
        backTrack(gc,2,n);
        return gc;
    }
};