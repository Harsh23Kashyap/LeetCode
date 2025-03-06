class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n=grid.size();
        n=n*n;
        long long os=n*(n+1)/2;
        long long dos=n*(n+1)*(2*n+1)/6;
        long long sum=0;
        long long dsum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                sum+=grid[i][j];
                dsum+=grid[i][j]*grid[i][j];
            }
        }
        // cout<<sum<<" "<<dsum<<endl;
        long long x_y=os-sum;
        // cout<<x_y<<endl;
        long long x2_y2=dos-dsum;
        // cout<<x2_y2<<endl;
        long long xplusy=x2_y2/x_y;
        int x=(xplusy-x_y)/2;
        int y=xplusy-x;
        return {x,y};
    }
};