class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) 
    {
        long long sum=0,large=0,small=0;
        for(int i=0;i<d.size();i++)
        {
            sum+=d[i];
            large=max(sum,large);
            small=min(sum,small);
        }
        large=upper-large;
        small=lower-small;
        if(large<small) return 0;
        return large-small+1;
    }
};