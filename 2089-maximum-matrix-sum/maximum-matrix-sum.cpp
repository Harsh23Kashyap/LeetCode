class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();
        long long  sum=0;
        int mini=INT_MAX;
        int nc=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(m[i][j]<0 )
                    nc++;
                mini=min(mini,abs(m[i][j]));
                sum+=abs(m[i][j]);
            }
        }
        return nc%2==0?sum:sum-mini-mini;

    }
};